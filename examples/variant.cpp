//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/recursive.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <ostream>
#include <cstdlib>

namespace
{

struct visitor
{
	typedef void result_type;

	template<
		typename T1,
		typename T2
	>
	result_type
	operator()(
		T1 const &t1,
		T2 const &t2
	) const
	{
		fcppt::io::cout
			<< t1
			<< FCPPT_TEXT(' ')
			<< t2
			<< FCPPT_TEXT('\n');
	}
};

struct wrapper;

typedef fcppt::variant::object<
	boost::mpl::vector2<
		fcppt::variant::recursive<
			wrapper
		>,
		int
	>
> recursive_variant;

struct wrapper
{
	wrapper(
		recursive_variant const &member
	)
	:
		member(member)
	{}

	recursive_variant member;
};

template<
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator <<(
	std::basic_ostream<
		Ch,
		Traits
	> &stream_,
	wrapper const &wrapper_
)
{
	return
		stream_ << wrapper_.member;
}

}

int main()
try
{
	typedef fcppt::variant::object<
		boost::mpl::vector2<
			int,
			fcppt::string
		>
	> variant;

	variant v(
		fcppt::string(
			FCPPT_TEXT("blabla")
		)
	);

	variant u(
		42
	);

	fcppt::variant::apply_binary(
		visitor(),
		v,
		u
	);

	recursive_variant rv(
		42
	);

	recursive_variant rrv((
		wrapper(
			rv
		)
	));

	fcppt::io::cout
		<< rrv
		<< FCPPT_TEXT('\n');
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}
