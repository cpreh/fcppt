//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_RECORD_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/mpl/all_of.hpp>
#include <fcppt/record/element_to_type_tpl.hpp>
#include <fcppt/record/is_element.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform_view.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief TODO...

\ingroup fcpptrecord
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

	typedef
	typename
	boost::fusion::result_of::as_vector<
		boost::mpl::transform_view<
			all_types,
			fcppt::record::element_to_type_tpl<
				boost::mpl::_1
			>
		>
	>::type
	tuple;

	object();

	explicit
	object(
		fcppt::no_init const &
	);

	explicit
	object(
		fcppt::no_init &&
	);

	template<
		typename ...Args
	>
	explicit
	object(
		Args && ...
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

	template<
		typename Label
	>
	fcppt::record::label_value_type<
		this_type,
		Label
	> const &
	get() const;

	tuple const &
	impl() const;
private:
	tuple elements_;
};

}
}

#endif
