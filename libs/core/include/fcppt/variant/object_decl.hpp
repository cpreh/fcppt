//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/brigand/is_set.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/is_brigand_sequence.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/disable_object.hpp>
#include <fcppt/variant/detail/std_type.hpp>


namespace fcppt
{
namespace variant
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A class that can hold any object from a fixed set of types

\ingroup fcpptvariant

\tparam Types An MPL sequence of types that must be CopyConstructible or
Movable, Assignable or AssignMovable and complete. It therefore must also not
be const.

See the \link fcpptvariant module description \endlink for more information.
*/
template<
	typename Types
>
class object
{
public:
	static_assert(
		fcppt::type_traits::is_brigand_sequence<
			Types
		>::value,
		"Types must be a brigand sequence"
	);

	static_assert(
		fcppt::brigand::is_set<
			Types
		>::value,
		"Variant types must form a set"
	);

	typedef
	fcppt::variant::detail::std_type<
		Types
	>
	std_type;

	/**
	\brief The brigand sequence of the possible types
	*/
	typedef
	Types
	types;

	/**
	\brief Constructs the variant from a value

	\tparam U Must be a type among <code>types</code>
	*/
	template<
		typename U
	>
	explicit
	object(
		U const &
	);

	/**
	\brief Move constructs the variant from a value

	Move constructs the variant from \a value.

	\tparam U Must be a type among <code>types</code>
	*/
	template<
		typename U,
		typename =
			fcppt::variant::detail::disable_object<
				U,
				object
			>
	>
	explicit
	object(
		U &&
	);

	/**
	\brief Returns a const reference to the held type without any checks.

	\tparam U Must be a type among <code>types</code>

	\warning The behaviour is undefined if the variant does not contain <code>U</code>.
	*/
	template<
		typename U
	>
	U const &
	get_unsafe() const;

	/**
	\brief Returns a reference to the held type without any checks.

	\tparam U Must be a type among <code>types</code>

	\warning The behaviour is undefined if the variant does not contain <code>U</code>.
	*/
	template<
		typename U
	>
	U &
	get_unsafe();

	/**
	\brief Returns the index of the held type

	\return A runtime index into <code>types</code> of the held type.
	*/
	fcppt::variant::size_type
	type_index() const;

	/**
	\brief Returns if the variant is invalid.

	This can only happen if an assignment of a different type throws an
	exception. There is no way to recover from that, except for falling
	back to heap allocation. An invalid variant should only be destroyed or
	assigned to.
	*/
	bool
	is_invalid() const;

	std_type &
	impl();

	std_type const &
	impl() const;
private:
	std_type impl_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
