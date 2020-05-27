import pytest
import GoExtExample


@pytest.mark.parametrize("input", [1000, 100000, 1000000])
def test_go(benchmark, input):
    benchmark(GoExtExample.sieve_of_eratosthenes, input)
