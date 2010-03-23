//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/raw_type.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/mpl/max_value.hpp>
#include <fcppt/alignment/array.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <typeinfo>

namespace fcppt
{
namespace variant
{

/// A class that can hold any object from a set of types
template<
	typename Types
>
class object
{
public:
	typedef Types types;

	object();

	// intentionally not explicit
	template<
		typename U
	>
	object(
		U const &
	);

	object(
		object const &
	);

	template<
		typename U
	>
	object &
	operator=(
		U const &
	);

	object &
	operator=(
		object const &
	);

	~object();

	bool
	empty() const;

	/// Returns the held object if its actual type is @a U
	template<
		typename U
	>
	U const &
	get() const;

	template<
		typename U
	>
	U &
	get();

	/// Returns the raw type if its actual type is @a U
	/**
	 * Note that the recursive type might be returned as well
	*/
	template<
		typename U
	>
	U const &
	get_raw() const;

	template<
		typename U
	>
	U &
	get_raw();

	/// Returns the type_info of the held object
	std::type_info const &
	type() const;

	/// Returns the index of the held type in the type list
	size_type
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

	static size_type const elements =
		boost::mpl::size<
			Types
		>::value
	;

	typedef typename alignment::array<
		raw_type,
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
	size_type index_;
	void *data_;
};

}
}

#endif
