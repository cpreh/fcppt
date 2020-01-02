//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace
{

void
coding_style_loop(
	int const n
)
{
// ![coding_style_loop]
int result{0};
for(int i{1}; i < n; ++i) result += i;
// ![coding_style_loop]
}

void
coding_style_fold(
	int const n
)
{
// ![coding_style_fold]
fcppt::algorithm::fold(
	fcppt::make_int_range(1,n),
	0,
	[](int i, int result) { return i + result; }
)
// ![coding_style_fold]
;
}

template<
	typename T
>
T
from_index(
	std::size_t const _value
)
{
	return
		static_cast<
			T
		>(
			_value
		);
}

// ![coding_style_make_array]
template<typename T, std::size_t N>
std::array<T,N> make_array();
// ![coding_style_make_array]

template<typename T, std::size_t N>
std::array<T,N> make_array()
{
// ![coding_style_array_init]
return fcppt::container::array::init<std::array<T,N>>(
	[](std::size_t i) { return from_index<T>(i); });
// ![coding_style_array_init]
}

}

int
main()
{
	coding_style_loop(
		42
	);

	coding_style_fold(
		42
	);

	make_array<
		int,
		4
	>();
}
