//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_RECORD_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/metal/as_tuple.hpp>
#include <fcppt/metal/is_set.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/enable_vararg_ctor.hpp>
#include <fcppt/record/is_element.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_fwd.hpp>
#include <fcppt/record/detail/label_list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/trait.hpp>
#include <metal/list/all_of.hpp>
#include <metal/list/list.hpp>
#include <metal/list/transform.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4521)
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A generic struct that identifies elements by types.

\ingroup fcpptrecord

A record of an MPL sequence #fcppt::record::element
<code>element<L_1,T_1>,...,element<L_n,T_n></code> contains an object
of type <code>T_i</code>, accessible by <code>L_i</code>,
for every <code>i = 1,...,n</code>.

\tparam Types An MPL sequence of #fcppt::record::element.
*/
template<
	typename Types
>
class object
{
public:
	static_assert(
		::metal::is_list<
			Types
		>::value,
		"Types must be a metal list"
	);

	static_assert(
		::metal::all_of<
			Types,
			::metal::trait<
				fcppt::record::is_element
			>
		>::value,
		"Types of record::object must all be fcppt::record::element<>"
	);

	static_assert(
		fcppt::metal::is_set<
			fcppt::record::detail::label_list<
				Types
			>
		>::value,
		"Labels of record::object must form a set"
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
	fcppt::metal::as_tuple<
		::metal::transform<
			::metal::lambda<
				fcppt::record::element_to_type
			>,
			all_types
		>
	>
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
	\brief Generic constructor.

	Initializing an <code>element<L_i,T_i></code> is done by calling
	<code>L_i{} = v_i</code> where <code>v_i</code> is of type <code>T_i</code>.

	The constructor checks that each <code>L_i</code> appears exactly once in \a Args.

	\param _args A parameter pack, obtained by assignment to #fcppt::record::label.

	\tparam Args Implementation-defined init types, obtained by assignment
	to #fcppt::record::label.
	*/
	template<
		typename ...Args,
		typename =
			fcppt::record::enable_vararg_ctor<
				Args...
			>
	>
	explicit
	object(
		Args && ..._args
	);

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
