//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/make_literal_fwd.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

// ![literal_motivation]
template<
	typename T
>
T
half(
	T const _value
)
{
	return
		_value
		/
		2;
}
// ![literal_motivation]

// ![literal_strong_typedef_1]
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

void
try_strong()
{
	// Doesn't work
	/*half(
		strong_int(
			10
		)
	);*/
}
// ![literal_strong_typedef_1]
}

// ![literal_custom_type]

namespace mine
{

class custom_type
{
public:
	static
	custom_type
	make(
		int const _value
	)
	{
		return
			custom_type{
				_value
			};
	}

	int
	get() const
	{
		return
			value_;
	}
private:
	explicit
	custom_type(
		int const _value
	)
	:
		value_{
			_value
		}
	{
	}

	int value_;
};

inline
custom_type
operator/(
	custom_type const _left,
	custom_type const _right
)
{
	return
		custom_type::make(
			_left.get()
			/
			_right.get()
		);
}

}
// ![literal_custom_type]


// ![literal_specialize]
namespace fcppt
{

template<>
struct make_literal<
	mine::custom_type
>
{
	typedef
	mine::custom_type
	decorated_type;

	template<
		typename Fundamental
	>
	static
	mine::custom_type
	get(
		Fundamental const _value
	)
	{
		static_assert(
			std::is_same<
				Fundamental,
				int
			>::value,
			"custom_types should be initialized by integers"
		);

		return
			mine::custom_type::make(
				_value
			);
	}
};

}
// ![literal_specialize]

namespace
{
// ![literal_half]
template<
	typename T
>
T
half_2(
	T const _value
)
{
	return
		_value
		/
		fcppt::literal<
			T
		>(
			2
		);
}
// ![literal_half]

// ![literal_use]
void
literal_use()
{
	// Prints 2
	std::cout
		<<
		half_2(
			mine::custom_type::make(
				4
			)
		).get()
		<<
		'\n';
}
// ![literal_use]

}

int
main()
{
	half(
		2
	);

	try_strong();

	literal_use();
}
