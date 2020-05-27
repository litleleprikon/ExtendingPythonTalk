import os
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import site

os.environ["CC"] = "gcc"

extension = Extension('GoExtExample',
                      sources=['GoExtExample.c'],
                      library_dirs=[os.getcwd(), ],
                      include_dirs=[
                          os.getcwd(),
                      ],
                      extra_link_args=[
                          '-dynamiclib GoExtExample.so']
                      )

setup(name='GoExtExample',
    version='1.0',
    description='This is Example module written in Go',
    ext_modules=[extension],
    # packages=[''],
    # package_dir={'': '.'},
    # package_data={'': ['GoExtensionExampleGo.so']},
    # include_package_data=True
      )
