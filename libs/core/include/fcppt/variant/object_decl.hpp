//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/brigand/max_value.hpp>
#include <fcppt/type_traits/is_brigand_sequence.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/disable_object.hpp>
#include <fcppt/variant/detail/nothrow_move_assignable.hpp>
#include <fcppt/variant/detail/nothrow_move_constructible.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/misc/sizeof.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

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

	/**
	\brief An mpl sequence of the possible types
	*/
	typedef Types types;

	/**
	\brief Constructs the variant from a value

	Constructs the variant from \a value.

	\tparam U Must be a type among <code>types</code>
	*/
	template<
		typename U
	>
	explicit
	object(
		U const &value
	);

	/**
	\brief Move constructs the variant from a value

	Move constructs the variant from \a value.

	\tparam U Must be a type among <code>types</code>
	*/
	template<
		typename U
	>
	explicit
	object(
		U &&value,
		fcppt::variant::detail::disable_object<
			U,
			object
		> * = nullptr
	);

	/**
	\brief Copy constructs a variant

	Copy constructs the value held by \a other into the variant.
	*/
	object(
		object const &other
	);

	/**
	\brief Move constructs a variant

	Move constructs the value held by \a other into the variant.
	*/
	object(
		object &&other
	)
	noexcept(
		fcppt::variant::detail::nothrow_move_constructible<
			Types
		>::value
	);

	/**
	\brief Assigns a new value to the variant

	Assigns \a value to the variant. Calls the assignment operator of the
	held type when possible.

	\tparam U Must be a type among <code>types</code>
	*/
	template<
		typename U
	>
	object &
	operator=(
		U const &value
	);

	/**
	\brief Move assigns a new value to the variant

	Move assigns \a value to the variant. Calls the move assignment
	operator of the held type when possible.
	*/
	template<
		typename U
	>
	fcppt::variant::detail::disable_object<
		U,
		object
	> &
	operator=(
		U &&value
	);

	/**
	\brief Assigns a variant

	Assigns the value from \a other to the variant. Calls the assignment
	operator of the held type when possible.
	*/
	object &
	operator=(
		object const &other
	);

	/**
	\brief Move assigns a variant

	Move assigns the value from \a other to the variant. Calls the
	move assignment operator of the held type when possible.
	*/
	object &
	operator=(
		object &&other
	)
	noexcept(
		fcppt::variant::detail::nothrow_move_assignable<
			Types
		>::value
	);

	/**
	\brief Destroys the variant

	Calls the destructor of the held value.
	*/
	~object();

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
private:
	template<
		typename U
	>
	void
	construct(
		U const &
	);

	template<
		typename U
	>
	void
	move_from(
		U &&
	);

	void
	destroy();

	void
	swap_unequal(
		object &
	);

	void *
	raw_data();

	void const *
	raw_data() const;

	static fcppt::variant::size_type const elements =
		::brigand::size<
			Types
		>::value
	;

	typedef
	std::aligned_storage_t<
		fcppt::brigand::max_value<
			::brigand::transform<
				Types,
				::brigand::sizeof_<
					::brigand::_1
				>
			>
		>::value,
		fcppt::brigand::max_value<
			::brigand::transform<
				Types,
				std::alignment_of<
					::brigand::_1
				>
			>
		>::value
	>
	storage_type;

	storage_type storage_;

	fcppt::variant::size_type index_;
};

}
}

#endif
