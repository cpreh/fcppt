//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[recursivevariant
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/recursive.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <ostream>
#include <cstdlib>

namespace
{

// forward declare a wrapper struct that can hold the to be declared variant again
struct wrapper;

// typedef a variant that can either hold an int or a struct wrapper
// note, that wrapper has be made recursive
typedef fcppt::variant::object<
	boost::mpl::vector2<
		fcppt::variant::recursive<
			wrapper
		>,
		int
	>
> recursive_variant;

// wrapper can hold the variant again!
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

// declare an output operator for wrapper (just for our test case)
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
	// the variant can hold an int
	recursive_variant rv(
		42
	);

	// or it can hold a wrapper struct, holding a variant of the same type in return
	recursive_variant rrv((
		wrapper(
			rv
		)
	));

	// rrv will be correctly dispatched to our wrapper struct, which will output the int
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
//]
