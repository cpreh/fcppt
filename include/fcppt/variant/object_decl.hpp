//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/mpl/max_value.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/disable_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/alignment_of.hpp>
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
	/**
	\brief An mpl sequence of the possible types
	*/
	typedef Types types;

	/**
	\brief Constructs the variant from a value

	Constructs the variant from \a value. This constructor is intentionally
	not explicit.

	\tparam U Must be a type among <code>types</code>

	\param value The value to construct the variant from

	\post <code>fcppt::variant::holds_type<U>(*this)</code> is true
	*/
	template<
		typename U
	>
	object(
		U const &value
	);

	/**
	\brief Move constructs the variant from a value

	Move constructs the variant from \a value. This constructor is
	intentionally not explicit.

	\tparam U Must be a type among <code>types</code>

	\param value The value to move construct the variant from

	\post <code>fcppt::variant::holds_type<U>(*this)</code> is true
	*/
	template<
		typename U
	>
	object(
		U &&value,
		typename fcppt::variant::detail::disable_object<
			U
		>::type * = nullptr
	);

	/**
	\brief Copy constructs a variant

	Copy constructs the value held by \a other into the variant.

	\param other The variant to copy from

	\post <code>this->type_index() == other.type_index()</code>
	*/
	object(
		object const &other
	);

	/**
	\brief Move constructs a variant

	Move constructs the value held by \a other into the variant.

	\param other The variant to move from

	\post <code>this->type_index() == other.type_index()</code>
	*/
	object(
		object &&other
	);

	/**
	\brief Assigns a new value to the variant

	Assigns \a value to the variant. Calls the assignment operator of the
	held type when possible.

	\tparam U Must be a type among <code>types</code>

	\param value The value to assign the variant from

	\post <code>fcppt::variant::holds_type<U>(*this)</code> is true
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

	\tparam U Must be a type among <code>types</code>

	\param value The value to assign the variant from

	\post <code>fcppt::variant::holds_type<U>(*this)</code> is true
	*/
	template<
		typename U
	>
	typename fcppt::variant::detail::disable_object<
		U,
		object &
	>::type
	operator=(
		U &&value
	);

	/**
	\brief Assigns a variant

	Assigns the value from \a other to the variant. Calls the assignment
	operator of the held type when possible.

	\param other The variant to assign from

	\post <code>this->type_index() == other.type_index()</code>
	*/
	object &
	operator=(
		object const &other
	);

	/**
	\brief Move assigns a variant

	Move assigns the value from \a other to the variant. Calls the
	move assignment operator of the held type when possible.

	\param other The variant to assign from
	*/
	object &
	operator=(
		object &&other
	);

	/**
	\brief Destroys the variant

	Calls the destructor of the held value.
	*/
	~object();

	/**
	\brief Returns a const reference to the held type

	If <code>fcppt::variant::holds_type<U>(*this)</code> is true, then a
	const reference to currently held value is be returned.

	\tparam U Must be a type among <code>types</code>

	\throw fcppt::variant::invalid_get if
	<code>fcppt::variant::holds_type<U>(*this)</code> is false
	*/
	template<
		typename U
	>
	U const &
	get() const;

	/**
	\brief Returns a reference to the held type

	If <code>fcppt::variant::holds_type<U>(*this)</code> is true, then a
	reference to currently held value is be returned.

	\tparam U Must be a type among <code>types</code>

	\throw fcppt::variant::invalid_get if
	<code>fcppt::variant::holds_type<U>(*this)</code> is false
	*/
	template<
		typename U
	>
	U &
	get();

	/**
	\brief Returns a const reference to the held type without any checks

	If <code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is true, a const reference to currently held
	value is be returned.

	\tparam U Must be a type among <code>types</code>

	\warning The behaviour is undefined if
	<code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is false.
	*/
	template<
		typename U
	>
	U const &
	get_unchecked() const;

	/**
	\brief Returns a reference to the held type without any checks

	If <code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is true, a reference to currently held value
	is be returned.

	\tparam U Must be a type among <code>types</code>

	\warning The behaviour is undefined if
	<code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is false.
	*/
	template<
		typename U
	>
	U &
	get_unchecked();

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
	back to heap allocation. An invalid variant should only be used
	destroyed or assigned to.
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
		boost::mpl::size<
			Types
		>::value
	;

	typedef typename std::aligned_storage<
		fcppt::mpl::max_value<
			Types,
			boost::mpl::sizeof_<
				boost::mpl::_1
			>
		>::value,
		fcppt::mpl::max_value<
			Types,
			boost::alignment_of<
				boost::mpl::_1
			>
		>::value
	>::type storage_type;

	storage_type storage_;

	fcppt::variant::size_type index_;
};

}
}

#endif
