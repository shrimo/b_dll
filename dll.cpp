#include <iostream>
#include <boost/python.hpp>
#include <boost/config.hpp>

using namespace std;
namespace py = boost::python;

#define API extern "C" BOOST_SYMBOL_EXPORT

API py::list get_list(py::object in_list)
{
	py::list out_list;
	for (int i = 0; i < len(in_list); i++)
	{
		string t_str = py::extract<string>(in_list[i]);
		out_list.append(t_str + " + external data");
	}
	return out_list;
}
