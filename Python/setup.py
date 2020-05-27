#!/usr/bin/env python3

import setuptools

setuptools.setup(
    name="PythonExtExample",
    version="0.0.1",
    author="Example Author",
    author_email="author@example.com",
    description="A small example package",
    packages=['PythonExtExample'],
    package_dir={'PythonExtExample': 'PythonExtExample'}
)
