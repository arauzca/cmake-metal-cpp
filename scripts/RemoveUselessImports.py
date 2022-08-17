#!/usr/bin/python

#--------------------------------------------------------------------------------------------------------------------------------------------------------------
#
# scripts/RemoveUselessImports.py
#
# Copyright 2022 Carlos Arauz.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#--------------------------------------------------------------------------------------------------------------------------------------------------------------

import argparse
import sys
import os
import re
import importlib
from pathlib import Path

#--------------------------------------------------------------------------------------------------------------------------------------------------------------

def parse_arguments():
  parser = argparse.ArgumentParser()
  parser.add_argument( dest = 'header_path', metavar = 'HEADER_FILE', help = 'Input header file to remove useless imports.' )

  args = parser.parse_args()

  return args

#--------------------------------------------------------------------------------------------------------------------------------------------------------------

def remove_useless_imports( args ):
  header = Path( os.path.realpath( args.header_path ) )
  dir = header.parent
  ext = header.suffix
  temporary_header = f'{dir}/temp{ext}'

  try:
    if header.exists:
      with open( file = header, mode = 'r' ) as input:
        with open( file = temporary_header, mode = 'w' ) as output:
          for line in input:
            search = re.search('#include <(Foundation|Metal|QuartzCore|AppKit|MetalKit)/', line)
            if not search:
              output.write(line)

      os.replace(temporary_header, header)

  except ( KeyboardInterrupt, SystemExit ):
    pass
  except:
    raise

#--------------------------------------------------------------------------------------------------------------------------------------------------------------

if __name__ == '__main__':
  result = -1

  try:
    if sys.getdefaultencoding().lower() == 'ascii':
      importlib.reload( sys )
      sys.setdefaultencoding( 'utf-8' )

    args = parse_arguments()

    remove_useless_imports( args )

    result = 0

  except ( KeyboardInterrupt, SystemExit ):
    pass
  except:
    raise