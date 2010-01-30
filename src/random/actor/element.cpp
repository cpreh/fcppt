//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/random/actor/element.hpp>

fcppt::random::actor::element::element(
	float_type const prob_,
	actor::callback const &callback_
)
:
	prob_(prob_),
	callback_(callback_)
{}

fcppt::random::actor::float_type const &
fcppt::random::actor::element::prob() const
{
	return prob_;
}

fcppt::random::actor::callback const &
fcppt::random::actor::element::callback() const
{
	return callback_;
}
