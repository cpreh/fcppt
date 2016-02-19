//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[vectoraccess
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/vector/static.hpp>


int
main()
{
	typedef fcppt::math::vector::static_<
		float,
		2
	> float2_vec;

	float2_vec obj(
		1.f,
		2.f
	);

	obj.x() = 42.f;

	fcppt::io::cout()
		<< obj.x()
		<< ' '
		<< obj.y()
		<< FCPPT_TEXT('\n');
}
//]
