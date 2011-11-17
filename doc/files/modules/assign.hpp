/**
\defgroup fcpptassign fcppt::assign
\brief A replacement for <a href="http://www.boost.org/doc/libs/1_47_0/libs/assign/doc/index.html">boost::assign</a>
This part of fcppt is similar to `boost::assign`, but fixes one issue: Why is
there `list_of`, which has a method `to_container`? Why not just a single
templated `make_container` function? This is exactly what `fcppt::assign`
consists of. It even works for associative containers (like `std::map` or
`std::set`), because it uses the generic insert function that takes an
iterator.
*/

/// The top level namespace
namespace fcppt
{
/**
\brief A replacement for <a href="http://www.boost.org/doc/libs/1_47_0/libs/assign/doc/index.html">boost::assign</a>
\details
This part of fcppt is similar to `boost::assign`, but fixes one issue: Why is
there `list_of`, which has a method `to_container`? Why not just a single
templated `make_container` function? This is exactly what `fcppt::assign`
consists of. It even works for associative containers (like `std::map` or
`std::set`), because it uses the generic insert function that takes an
iterator.
*/
namespace assign {}
}
