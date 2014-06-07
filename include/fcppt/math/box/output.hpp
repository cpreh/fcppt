//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_BOX_OUTPUT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Outputs a box to a basic_ostream
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>

The format will be

<pre>
(position,size)
</pre>
*/
template<
	typename T,
	size_type N,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<Ch, Traits> &_stream,
	object<T, N> const &_box
)
{
	return
		_stream
		<< _stream.widen('(')
		<< _box.pos()
		<< _stream.widen(',')
		<< _box.size()
		<< _stream.widen(')');
}

}
}
}

#endif
