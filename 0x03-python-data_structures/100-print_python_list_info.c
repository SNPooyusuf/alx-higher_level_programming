#include <stdlib.h>
#include <stdio.h>
#include <python.h>
/**
 * print_python_list_info -  function that prints some basic
 *							info about Python lists
 * @p: python list
 */
void print_python_list_info(PyObject *p)
{
	int elemant;

	printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (elemant = 0; elemant < Py_SIZE(p); elemant++)
		printf("Element %d: %s\n", elemant, Py_TYPE(PyList_GetItem(p, elemant))->tp_name);
}
