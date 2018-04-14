//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_MAP_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_MAP_HPP_INCLUDED


namespace fcppt
{

template<
	typename StrongTypedef,
	typename Function
>
inline
auto
strong_typedef_map(
	StrongTypedef &&_input,
	Function const &_function
)
->
fcppt::strong_typedef<
	decltype(
		_function(
			fcppt::move_if_rvalue<
				StrongTypedef
			>(
				_input.get()
			)
		)
	),
	fcppt::strong_typedef_tag<
		fcppt::type_traits::remove_cv_ref<
			StrongTypedef
		>
	>
>
{
	typedef
	fcppt::type_traits::remove_cv_ref<
		StrongTypedef
	>
	input_type;

	static_assert(
		fcppt::is_strong_typedef<
			input_type
		>::value,
		"StrongTypedef must be a strong typedef"
	);

	return
		fcppt::strong_typedef<
			decltype(
				_function(
					fcppt::move_if_rvalue<
						StrongTypedef
					>(
						_input.get()
					)
				)
			),
			fcppt::strong_typedef_tag<
				input_type
			>
		>(
			_function(
				fcppt::move_if_rvalue<
					StrongTypedef
				>(
					_input.get()
				)
			)
		);
}

}

#endif
