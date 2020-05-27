from setuptools import setup, Extension

extension = Extension('CExtExample',
                      sources=['CExtExample.c'])

setup(name='CExtExample',
      version='1.0',
      description='This is Example module written in C',
      ext_modules=[extension])
