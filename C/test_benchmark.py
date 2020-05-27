import pytest
import CExtExample


@pytest.mark.parametrize("input", [1000, 100000, 1000000])
def test_c(benchmark, input):
    benchmark(CExtExample.sieve_of_eratosthenes, input)
