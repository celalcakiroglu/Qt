# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake 2.8\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake 2.8\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "C:\Program Files (x86)\CMake 2.8\bin\cmake-gui.exe"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Program Files\Work\created by me\QT\lapack-3.4.2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Program Files\Work\created by me\QT\lapackBinaries"

# Include any dependencies generated for this target.
include BLAS/TESTING/CMakeFiles/xblat1s.dir/depend.make

# Include the progress variables for this target.
include BLAS/TESTING/CMakeFiles/xblat1s.dir/progress.make

# Include the compile flags for this target's objects.
include BLAS/TESTING/CMakeFiles/xblat1s.dir/flags.make

BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj: BLAS/TESTING/CMakeFiles/xblat1s.dir/flags.make
BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj: E:/Program\ Files/Work/created\ by\ me/QT/lapack-3.4.2/BLAS/TESTING/sblat1.f
	$(CMAKE_COMMAND) -E cmake_progress_report "E:\Program Files\Work\created by me\QT\lapackBinaries\CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building Fortran object BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj"
	cd /d E:\PROGRA~1\Work\CREATE~1\QT\LAPACK~1\BLAS\TESTING && C:\MinGW\bin\gfortran.exe  $(Fortran_DEFINES) $(Fortran_FLAGS) -c "E:\Program Files\Work\created by me\QT\lapack-3.4.2\BLAS\TESTING\sblat1.f" -o CMakeFiles\xblat1s.dir\sblat1.f.obj

BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj.requires:
.PHONY : BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj.requires

BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj.provides: BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj.requires
	$(MAKE) -f BLAS\TESTING\CMakeFiles\xblat1s.dir\build.make BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj.provides.build
.PHONY : BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj.provides

BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj.provides.build: BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj

# Object files for target xblat1s
xblat1s_OBJECTS = \
"CMakeFiles/xblat1s.dir/sblat1.f.obj"

# External object files for target xblat1s
xblat1s_EXTERNAL_OBJECTS =

bin/xblat1s.exe: BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj
bin/xblat1s.exe: BLAS/TESTING/CMakeFiles/xblat1s.dir/build.make
bin/xblat1s.exe: lib/libblas.dll.a
bin/xblat1s.exe: BLAS/TESTING/CMakeFiles/xblat1s.dir/objects1.rsp
bin/xblat1s.exe: BLAS/TESTING/CMakeFiles/xblat1s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking Fortran executable ..\..\bin\xblat1s.exe"
	cd /d E:\PROGRA~1\Work\CREATE~1\QT\LAPACK~1\BLAS\TESTING && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\xblat1s.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
BLAS/TESTING/CMakeFiles/xblat1s.dir/build: bin/xblat1s.exe
.PHONY : BLAS/TESTING/CMakeFiles/xblat1s.dir/build

BLAS/TESTING/CMakeFiles/xblat1s.dir/requires: BLAS/TESTING/CMakeFiles/xblat1s.dir/sblat1.f.obj.requires
.PHONY : BLAS/TESTING/CMakeFiles/xblat1s.dir/requires

BLAS/TESTING/CMakeFiles/xblat1s.dir/clean:
	cd /d E:\PROGRA~1\Work\CREATE~1\QT\LAPACK~1\BLAS\TESTING && $(CMAKE_COMMAND) -P CMakeFiles\xblat1s.dir\cmake_clean.cmake
.PHONY : BLAS/TESTING/CMakeFiles/xblat1s.dir/clean

BLAS/TESTING/CMakeFiles/xblat1s.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Program Files\Work\created by me\QT\lapack-3.4.2" "E:\Program Files\Work\created by me\QT\lapack-3.4.2\BLAS\TESTING" "E:\Program Files\Work\created by me\QT\lapackBinaries" "E:\Program Files\Work\created by me\QT\lapackBinaries\BLAS\TESTING" "E:\Program Files\Work\created by me\QT\lapackBinaries\BLAS\TESTING\CMakeFiles\xblat1s.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : BLAS/TESTING/CMakeFiles/xblat1s.dir/depend

