//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIQUE_PTR_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/use.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Casts a unique_ptr to a derived class.

Tries to cast the given unique ptr to \a Derived using the cast function \a
Cast. The result is either a unique_ptr of type \a Derived, or (if the cast
fails) of type \a Base.

\ingroup fcpptsmartptr

\tparam Cast A cast function from \ref fcpptcasts
*/
template<
	typename Cast,
	typename Derived,
	typename Base,
	typename Deleter
>
inline
fcppt::variant::object<
	fcppt::unique_ptr<
		Derived,
		Deleter
	>,
	fcppt::unique_ptr<
		Base,
		Deleter
	>
>
unique_ptr_dynamic_cast(
	fcppt::unique_ptr<
		Base,
		Deleter
	> &&_other
)
noexcept
{
	using
	result_type
	=
	fcppt::variant::object<
		fcppt::unique_ptr<
			Derived,
			Deleter
		>,
		fcppt::unique_ptr<
			Base,
			Deleter
		>
	>;

	static_assert(
		fcppt::type_traits::is_base_of<
			Base,
			Derived
		>::value,
		"Base must be a base class of Derived"
	);

	return
		fcppt::optional::maybe(
			fcppt::cast::apply<
				Cast,
				Derived
			>(
				*_other
			),
			[
				&_other
			]{
				return
					result_type{
						std::move(
							_other
						)
					};
			},
			[
				&_other
			](
				fcppt::reference<
					Derived
				> const _derived
			)
			{
				FCPPT_USE(
					_other.release_ownership()
				);

				return
					result_type{
						fcppt::unique_ptr<
							Derived,
							Deleter
						>{
							&_derived.get()
						}
					};
			}
		);
}

}

#endif
