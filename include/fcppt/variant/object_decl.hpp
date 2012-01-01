//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/alignment/array.hpp>
#include <fcppt/mpl/max_value.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/raw_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief A class that can hold any object from a fixed set of types
\ingroup fcpptvariant
\tparam Types An MPL sequence of types that must be <code>CopyConstructible</code>, <code>Assignable</code> and complete.

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

	\tparam U Must be a type or a type contained in an
	fcppt::variant::recursive among <code>types</code>

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
	\brief Copy constructs a variant

	Copy constructs the value held by \a other into the variant.

	\param other The variant to copy from

	\post <code>this->type_index() == other.type_index()</code>
	*/
	object(
		object const &other
	);

	/**
	\brief Assigns a new value to the variant

	Assigns \a value to the variant. Calls the assignment operator of the
	held type when possible.

	\tparam U Must be a type or a type contained in an
	fcppt::variant::recursive among <code>types</code>

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
	\brief Destroys the variant

	Calls the destructor of the held value.
	*/
	~object();

	/**
	\brief Returns a const reference to the held type

	If <code>fcppt::variant::holds_type<U>(*this)</code> is true, then a
	const reference to currently held value is be returned.

	\tparam U Must be a type or a type contained in an
	fcppt::variant::recursive among <code>types</code>

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

	\tparam U Must be a type or a type contained in an
	fcppt::variant::recursive among <code>types</code>

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

	Note that this function does not transform recursive types, they will
	be returned as is.

	\tparam U Must be a type among <code>types</code>

	\warning The behaviour is undefined if
	<code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is false.
	*/
	template<
		typename U
	>
	U const &
	get_raw() const;

	/**
	\brief Returns a reference to the held type without any checks

	If <code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is true, a reference to currently held value
	is be returned.

	Note that this function does not transform recursive types, they will
	be returned as is.

	\tparam U Must be a type among <code>types</code>

	\warning The behaviour is undefined if
	<code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is false.
	*/
	template<
		typename U
	>
	U &
	get_raw();

	/**
	\brief Returns an <code>std::%type_info</code> of the held type
	*/
	std::type_info const &
	type() const;

	/**
	\brief Returns the index of the held type

	\return A runtime index into <code>types</code> of the held type.
	*/
	variant::size_type
	type_index() const;
private:
	template<
		typename U
	>
	void
	construct(
		U const &
	);

	void
	destroy();

	static variant::size_type const elements =
		boost::mpl::size<
			Types
		>::value
	;

	typedef typename alignment::array<
		variant::detail::raw_type,
		mpl::max_value<
			Types,
			boost::mpl::sizeof_<
				boost::mpl::_1
			>
		>::value,
		mpl::max_value<
			Types,
			boost::alignment_of<
				boost::mpl::_1
			>
		>::value
	>::type storage_type;

	storage_type storage_;

	variant::size_type index_;

	void *data_;
};

}
}

#endif
