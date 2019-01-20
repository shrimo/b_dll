#include <iostream>
#include <boost/dll.hpp>
#include <boost/python.hpp>
#include <boost/filesystem.hpp>

using namespace std;
namespace py = boost::python;

py::list boost_main(py::object in_list){	
	boost::filesystem::path path_dll = "dll.so";
	function<py::list(py::object)> func_ex;
	func_ex = boost::dll::import<py::list(py::object)>(path_dll, "get_list");
	py::list out_list;
	out_list = func_ex(in_list);
	return out_list;
}

BOOST_PYTHON_MODULE(main)
{	
    py::def("boost_main", &boost_main);
}
