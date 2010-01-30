//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/dynamic_cast.hpp>
#include <fcppt/try_dynamic_cast.hpp>
#include <fcppt/text.hpp>

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

int main()
try
{
	derived1 d1;

	base &b(
		d1
	);

#if 0
	fcppt::dynamic_cast_<
		derived2 &
	>(
		b
	);
#endif

	FCPPT_TRY_DYNAMIC_CAST(
		derived1 const *,
		ptr,
		&b
	)
		fcppt::io::cout
			<< ptr
			<< FCPPT_TEXT('\n');
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
}
