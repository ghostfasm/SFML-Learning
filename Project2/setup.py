from distutils.core import setup, Extension

module = Extension("myModule", sources = ["myModule.cpp"])

setup(name="fputs",
    version="2.0",
    description="This is a package for myModule",
    author="liefasm",
    author_email="liefasm@gmail.com",
    ext_modules= [module])