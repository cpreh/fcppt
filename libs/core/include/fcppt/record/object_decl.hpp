//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_RECORD_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/mpl/all_of.hpp>
#include <fcppt/mpl/sequence_to_tuple.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_to_type_tpl.hpp>
#include <fcppt/record/is_element.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform_view.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4521)

/**
\brief A generic struct that identifies elements by types.

\ingroup fcpptrecord

A record of an MPL sequence \link fcppt::record::element\endlink
<code>element<L_1,T_1>,...,element<L_n,T_n></code> contains an object
of type <code>T_i</code>, accessible by <code>L_i</code>,
for every <code>i = 1,...,n</code>.

\tparam Types An MPL sequence of \link fcppt::record::element\endlink.
*/
template<
	typename Types
>
class object
{
public:
	static_assert(
		fcppt::mpl::all_of<
			Types,
			fcppt::record::is_element<
				boost::mpl::_1
			>
		>::value,
		"Types of record::object must all be fcppt::record::element<>"
	);

	typedef
	fcppt::record::object<
		Types
	>
	this_type;

	typedef
	Types
	all_types;

	/**
	\brief The std::tuple type <code>(T_1,...,T_n)</code>.
	*/
	typedef
	typename
	fcppt::mpl::sequence_to_tuple<
		boost::mpl::transform_view<
			all_types,
			fcppt::record::element_to_type_tpl<
				boost::mpl::_1
			>
		>
	>::type
	tuple;

	/**
	\brief Constructor for empty records

	Calling this if \a Types is not empty, a compile-time error occurs.
	*/
	object();

	/**
	\brief An uninitialized record

	Calls only default constructors for its elements. Use this with care.
	*/
	explicit
	object(
		fcppt::no_init const &
	);

	/**
	\brief An uninitialized record

	Calls only default constructors for its elements. Use this with care.
	*/
	explicit
	object(
		fcppt::no_init &&
	);

	/**
	\brief Generic constructor.

	Initializing an <code>element<L_i,T_i></code> is done by calling
	<code>L_i{} = v_i</code> where <code>v_i</code> is of type <code>T_i</code>.

	The constructor checks that each <code>L_i</code> appears exactly once in \a Args.

	\param _args A parameter pack, obtained by assignment to \link
	fcppt::record::label\endlink.

	\tparam Args Implementation-defined init types, obtained by assignment
	to \link fcppt::record::label\endlink.
	*/
	template<
		typename ...Args
	>
	explicit
	object(
		Args && ..._args
	);

	object(
		object const &
	);

	object(
		object &
	);

	object(
		object &&
	);

	object &
	operator=(
		object const &
	);

	object &
	operator=(
		object &&
	);

	~object();

	/**
	\brief Sets an element by copy.

	\see fcppt::record::set.
	*/
	template<
		typename Label
	>
	void
	set(
		fcppt::record::label_value_type<
			this_type,
			Label
		> const &
	);

	/**
	\brief Sets an element by move.

	\see fcppt::record::set.
	*/
	template<
		typename Label
	>
	void
	set(
		fcppt::record::label_value_type<
			this_type,
			Label
		> &&
	);

	/**
	\brief Gets an element.

	\see fcppt::record::get.
	*/
	template<
		typename Label
	>
	fcppt::record::label_value_type<
		this_type,
		Label
	> const &
	get() const;

	/**
	\brief Gets an element.

	\see fcppt::record::get.
	*/
	template<
		typename Label
	>
	fcppt::record::label_value_type<
		this_type,
		Label
	> &
	get();

	tuple const &
	impl() const;
private:
	tuple elements_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
