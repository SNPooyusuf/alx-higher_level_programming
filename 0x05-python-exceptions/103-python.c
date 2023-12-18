#include <Python.h>

void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        fprintf(stderr, "Invalid List Object\n");
        return;
    }

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
    for (Py_ssize_t i = 0; i < PyList_Size(p); ++i) {
        printf("Element %ld: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "Invalid Bytes Object\n");
        return;
    }

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", PyBytes_GET_SIZE(p));
    printf("  trying string: %s\n", PyBytes_AS_STRING(p));
    printf("  first 10 bytes: ");
    for (Py_ssize_t i = 0; i < PyBytes_GET_SIZE(p) && i < 10; ++i) {
        printf("%02hhx ", PyBytes_AS_STRING(p)[i]);
    }
    printf("\n");
}

void print_python_float(PyObject *p) {
    if (!PyFloat_Check(p)) {
        fprintf(stderr, "Invalid Float Object\n");
        return;
    }

    printf("[.] float object info\n");
    printf("  type: %s\n", Py_TYPE(p)->tp_name);
    printf("  value: %f\n", PyFloat_AS_DOUBLE(p));
}

