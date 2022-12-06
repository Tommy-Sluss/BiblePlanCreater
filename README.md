# Bible Maker Plan
A C++ Code to generate a Bible Maker Plan

Requires Cmake to be installed - can be installed through homebrew

you may have to change the conan cci server.
to do this:
install fresh copy of conan if not installed
add conan to path variables if needed
in terminal:
"Conan remote list"
remove all the remotes listed:
"Conan remote remove <remote name>"
for example:
"conan remote remove conancenter"

Finally,
"conan remote add cci https://center.conan.io"


To run on MacOS:
cd into the main repository
"mkdir build"
"cd build"
"cmake .."
"cd build/src"
"make"
"./BiblePlanMaker"