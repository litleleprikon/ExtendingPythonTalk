#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "GoExtExampleGo.h"

#if PY_MAJOR_VERSION >= 3

static PyObject *GoExtExample_SieveOfEratosthenes(PyObject *self, PyObject *args)
{
    int n;
    if (!PyArg_ParseTuple(args, "I", &n))
    {
        return NULL;
    }
    GoSlice primes = {};
    SieveOfEratosthenes((GoInt)n, &primes);
    PyObject *result = PyList_New(0);
    for (int i = 0; i < primes.len; i++)
    {
        GoInt current = ((GoInt *)(primes.data))[i];
        PyList_Append(result, PyLong_FromLong(current));
    }
    return result;
}

static PyMethodDef Methods[] = {
    {"sieve_of_eratosthenes", GoExtExample_SieveOfEratosthenes, METH_VARARGS,
     "Return list of prime numbers until given number."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static PyModuleDef GoExtExample = {
    PyModuleDef_HEAD_INIT,
    "GoExtExample",                 /* name of module */
    "Example module written in Go", /* module documentation, may be NULL */
    -1,                             /* size of per-interpreter state of the module,
                        or -1 if the module keeps state in global variables. */
    Methods};

PyObject *PyInit_GoExtExample(void)
{
    return PyModule_Create(&GoExtExample);
}
#endif
