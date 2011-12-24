//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [optional_dynamic_cast]

#include <fcppt/optional_dynamic_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cassert>
#include <fcppt/config/external_end.hpp>


namespace
{

struct base
{
	virtual ~base()
	{}
};

struct derived1
:
	base
{
};

struct derived2
:
	base
{
};

void
f()
{
	derived1 d1;

	base &base_ref = d1;

	// try to cast d1 into a d2, which will fail
	fcppt::optional<derived2 &> to_d2(
		fcppt::optional_dynamic_cast<derived2 &>(
			base_ref));

	assert(
		!to_d2.has_value());

	// This should work
	fcppt::optional<derived1 &> to_d1(
		fcppt::optional_dynamic_cast<derived1 &>(
			base_ref));

	assert(
		to_d1.has_value());
}

}
//! [optional_dynamic_cast]

int main()
{
	f();
}
