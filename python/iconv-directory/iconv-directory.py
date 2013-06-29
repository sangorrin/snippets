#!/usr/bin/env python
# This file executes the "iconv" command to modify the encoding of
# all files that have certain extensions under a specific root
# directory.
#
# First modify the constant "extensions", "FROM" and "TO". Then,
# run the script with:
#        $ python iconv-directory.py rootfolder
# Requirements: iconv, python
import os
import sys
import subprocess

# These constants can be modified
extensions = [".h", ".c", ".S"]
FROM = "EUCJP"
TO = "UTF-8"

# Check argument (root directory)
if len(sys.argv) < 2:
    sys.exit('Usage: %s root-directory' % sys.argv[0])

if not os.path.exists(sys.argv[1]):
    sys.exit('ERROR: root-directory %s was not found!' % sys.argv[1])

# Walk through the root directory and convert the encodings
for root, subFolders, files in os.walk(sys.argv[1]):
    for file in files:
        # Absolute path to the file
        path = os.path.abspath(os.path.join(root,file))
        # Modify "extensions" for the files you want to apply
        fileName, fileExtension = os.path.splitext(path)
        if fileExtension in extensions:
        # TODO: add checks to the encoding of the file. For Japanese 
        # encodings the tool "nfk" seems to work well, it can be used like:
        # out = subprocess.check_output("nkf --guess " + path, shell=True)
        # out = out.rstrip()
        # if out == "EUC-JP (LF)":
            cmd = "iconv -f " +FROM+ " -t " +TO+ " -o " +path+ " " + path
            print cmd
            subprocess.call(cmd, shell=True)


