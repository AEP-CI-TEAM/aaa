.SUFFIXES:				# ignore builtin rules
.PHONY: clean configure build clean_build

TYPE ?= Release

clean_build: clean configure build

clean:
	@echo 'Cleaning every build directory!'
	rm -rf build
configure:
	@echo 'CMAKE configure...!'
	cmake project_name_cmake -B build -G "Ninja" -DCMAKE_BUILD_TYPE:STRING=${TYPE} -DCMAKE_TOOLCHAIN_FILE:STRING=toolchain.cmake
build:
	@echo 'CMAKE build...!'
	cmake --build build --parallel --config ${TYPE}
