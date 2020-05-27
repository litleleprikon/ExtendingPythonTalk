import pytest
import PythonExtExample


@pytest.mark.parametrize("input", [1000, 100000, 1000000])
def test_python(benchmark, input):
    benchmark(PythonExtExample.sieve_of_eratosthenes, input)
