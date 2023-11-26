import os
from conan import ConanFile
from conan.tools.cmake import cmake_layout


class AsioGrpcRecipe(ConanFile):

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("boost/[~1.82]")
        self.requires("eigen/3.4.0")
        self.requires("fmt/[~10]")
        self.requires("gtest/cci.20210126")

        if self.settings.os == "Windows":
            self.requires("base64/[~0.4]")
    
    def build_requirements(self):
        if self.settings.os != "Windows":
            self.tool_requires("cmake/[>3.25]")

    def layout(self):
        cmake_layout(self)