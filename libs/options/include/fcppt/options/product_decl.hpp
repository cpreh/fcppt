//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRODUCT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/product_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/disjoint_product.hpp>


namespace fcppt
{
namespace options
{

template<
	typename Left,
	typename Right
>
class product
{
public:
	product(
		Left const &_left,
		Right const &_right
	);

	product(
		Left &&_left,
		Right &&_right
	);

	typedef
	fcppt::record::disjoint_product<
		typename
		Left::result_type,
		typename
		Right::result_type
	>
	result_type;

	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::state &
	) const;

	fcppt::options::has_parameter_set
	parameters() const;

	fcppt::string
	usage() const;
private:
	Left left_;

	Right right_;
};

}
}

#endif
