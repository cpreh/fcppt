/**
\defgroup fcpptassign fcppt::assign
\brief A replacement for <a href="http://www.boost.org/doc/libs/1_47_0/libs/assign/doc/index.html">boost::assign</a>
This part of fcppt is similar to <a href="http://www.boost.org/doc/libs/1_48_0/libs/assign/doc/index.html">boost::assign</a>, but fixes one issue: Why is there
<code>list_of</code>, which has a method <code>to_container</code>? Why not
just a single templated <code>make_container</code> function? This is exactly
what fcppt::assign consists of. It even works for associative containers (like
<code>%std::map</code> or <code>%std::set</code>), because it uses the generic insert function that takes an
iterator.
*/

/// The top level namespace
namespace fcppt
{
/*
\brief A replacement for <a href="http://www.boost.org/doc/libs/1_47_0/libs/assign/doc/index.html">\verbatim boost::assign \endverbatim</a>
\details
This part of fcppt is similar to <a href="http://www.boost.org/doc/libs/1_48_0/libs/assign/doc/index.html">\verbatim boost::assign \endverbatim</a>, but fixes one issue: Why is there
<code>list_of</code>, which has a method <code>to_container</code>? Why not
just a single templated <code>make_container</code> function? This is exactly
what fcppt::assign consists of. It even works for associative containers (like
<code>\verbatim std::map \endverbatim</code> or <code>\verbatim std::set
\endverbatim</code>), because it uses the generic insert function that takes an
iterator.
*/
namespace assign {}
}
