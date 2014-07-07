#!/bin/env python
"""
Python Buildscript for Jenkins

Very basic at the moment. It finds every directory under
$WORKSPACE/exercises, excluding the one named "template" and builds all
projects under there in separate directories.

It assumes the WORKSPACE environment variable exists and points to the root
of the clone repository.
"""
import os
import shutil
import subprocess as subp
import sys

# Common variables
WORKSPACE = os.environ["WORKSPACE"]
PROJECTS_ROOT = os.path.join(WORKSPACE, "exercises")
TEMPLATE_DIR_NAME = "template" #skip this directory

# Build directory structure
#   builds/
#         dirname1/
#         dirname2/
#         ...
# where dirname1 etc are the directories under PROJECTS_ROOT
BUILDS_ROOT = os.path.join(WORKSPACE, "builds")

################### Functions #########################################################

def is_windows():
    if sys.platform == "win32":
        return True
    else:
        return False

def run_cmake(cmakelists_path):


    if is_windows():
        cmake_exe = r"C:\Program Files (x86)\CMake 2.8\bin\cmake.exe"
        generator = 'Visual Studio 11 Win64'
    else:
        cmake_exe = "cmake"
        generator = 'Unix Makefiles'
    cmd = [cmake_exe, "-G", generator, cmakelists_path]
    print "Running '%s'" % " ".join(cmd)
    status = subp.call(cmd)

def generate_project(src_root, build_root):
    """
    Run cmake in the given build_root., assuming there is a CMakeLists.txt file
    in the src_dir
    """
    saveddir = os.getcwd()
    try:
        os.chdir(build_root)
        run_cmake(src_root)
    except Exception, exc:
        print "Error: %s" % str(exc)
    # Get back to where we started
    os.chdir(saveddir)

def build(build_root):
    """
    Build the code in the build_root directory
    """
    if is_windows():
        raise NotImplementedError("build is not implemented yet for Windows")
    else:
        cmd = ["make", "-C", build_root]
        print "Running '%s'" % " ".join(cmd)
        status = subp.call(cmd)

################### Main #########################################################

# Always perform a clean build
if os.path.exists(BUILDS_ROOT):
    print "Removing %s" % BUILDS_ROOT
    shutil.rmtree(BUILDS_ROOT)
print "Making %s" % BUILDS_ROOT
os.mkdir(BUILDS_ROOT)

dirnames = os.listdir(PROJECTS_ROOT)
dirnames.remove(TEMPLATE_DIR_NAME)
if len(dirnames) == 0:
    raise RuntimeError("No projects found to build")

for dirname in dirnames:
    print "Building",dirname
    src_root = os.path.join(PROJECTS_ROOT, dirname)
    build_root = os.path.join(BUILDS_ROOT, dirname)
    os.mkdir(build_root)
    generate_project(src_root, build_root)
    build(build_root)
    ##