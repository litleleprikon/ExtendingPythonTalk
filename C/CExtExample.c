#define PY_SSIZE_T_CLEAN
#include <Python.h>

#if PY_MAJOR_VERSION >= 3

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    int length;
    int *values;
} Array;

Array SieveOfEratosthenes(int n)
{
    int *values = malloc(sizeof(int[n]));
    Array result = {0, values};
    bool *sieve = malloc(sizeof(bool[n + 1]));
    for (int i = 0; i <= n; i++)
    {
        sieve[i] = true;
    }
    for (int p = 2; p <= n; p++)
    {
        if (sieve[p])
        {
            for (int i = p + p; i <= n; i += p)
            {
                sieve[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (sieve[p])
        {
            result.values[result.length] = p;
            result.length++;
        }
    }
    free(sieve);
    return result;
}

static PyObject *
CExtExample_SieveOfEratosthenes(PyObject *self, PyObject *args)
{
    int n;
    if (!PyArg_ParseTuple(args, "I", &n))
    {
        return NULL;
    }
    Array primes = SieveOfEratosthenes(n);
    PyObject *result = PyList_New(0);
    for (int i = 0; i < primes.length; i++)
    {
        PyList_Append(result, PyLong_FromLong(primes.values[i]));
    }
    return result;
}

static PyMethodDef Methods[] = {
    {"sieve_of_eratosthenes", CExtExample_SieveOfEratosthenes, METH_VARARGS,
     "Return list of prime numbers until given number."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static PyModuleDef CExtExample = {
    PyModuleDef_HEAD_INIT,
    "CExtExample",                 /* name of module */
    "Example module written in C", /* module documentation, may be NULL */
    -1,                            /* size of per-interpreter state of the module,
                        or -1 if the module keeps state in global variables. */
    Methods};

PyObject *PyInit_CExtExample(void)
{
    return PyModule_Create(&CExtExample);
}
#endif
