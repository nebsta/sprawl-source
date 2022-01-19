from conans import ConanFile, tools

class HelloConan(ConanFile):
    name = "sprawl-source"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    description = "2D Puzzle game built using Grumble"
    url = "None"
    license = "None"
    author = "Benjamin Wallis"
    topics = None
    requires = ["grumble/1.0.0"]
    generators = "xcode"

    def package(self):
        self.copy("*.a", "lib", "lib")
        self.copy("*.hpp", "include/grumble", "grumble")

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
