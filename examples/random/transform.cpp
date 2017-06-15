//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


// ![random_transform_my_type]
namespace mine
{

template<
	typename Type
>
class my_type
{
public:
	explicit
	my_type(
		Type const _value
	)
	:
		value_(
			_value
		)
	{
	}

	Type
	value() const
	{
		return value_;
	}
private:
	Type value_;
};

}
// ![random_transform_my_type]


//![random_transform_specialization]
#include <fcppt/type_iso/transform.hpp>


namespace fcppt
{
namespace type_iso
{

template<
	typename Type
>
struct transform<
	mine::my_type<
		Type
	>
>
{
	typedef
	mine::my_type<
		Type
	>
	decorated_type;

	typedef
	Type
	undecorated_type;

	// A static function that converts to the base type
	static
	undecorated_type
	undecorate(
		decorated_type const &_value
	)
	{
		return
			_value.value();
	}

	// A static function that converts from the base type
	static
	decorated_type
	decorated_value(
		undecorated_type const &_value
	)
	{
		return
			decorated_type(
				_value
			);
	}
};

}
}
//![random_transform_specialization]

#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>


int
main()
{
	typedef mine::my_type<
		int
	> my_int_type;

	typedef
	fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::uniform_int<
			my_int_type
		>
	>
	distribution;

	fcppt::io::cout()
		<<
		distribution(
			distribution::param_type::min(
				my_int_type(
					0
				)
			),
			distribution::param_type::max(
				my_int_type(
					10
				)
			)
		)
		<<
		FCPPT_TEXT('\n');
}
