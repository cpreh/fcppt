//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/random/actor/normalized.hpp>
#include <fcppt/random/actor/element.hpp>
#include <fcppt/random/make_inclusive_range.hpp>
#include <fcppt/random/exception.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/text.hpp>
#include <fcppt/format.hpp>
#include <fcppt/config/external_begin.hpp>
#include <numeric>
#include <functional>
#include <fcppt/config/external_end.hpp>

fcppt::random::actor::normalized::normalized(
	container const &_elements
)
:
	elements_(_elements),
	rng_(
		random::make_inclusive_range(
			static_cast<float_type>(0),
			std::accumulate(
				elements_.begin(),
				elements_.end(),
				static_cast<float_type>(0),
				std::tr1::bind(
					std::plus<
						float_type
					>(),
					std::tr1::placeholders::_1,
					std::tr1::bind(
						&element::prob,
						std::tr1::placeholders::_2
					)
				)
			)
		)
	)
{
	if(
		elements_.empty()
	)
		throw random::exception(
			FCPPT_TEXT("actor::normalized: elements may not be empty!")
		);
}

fcppt::random::actor::normalized::~normalized()
{}

void
fcppt::random::actor::normalized::operator()()
{
	float_type const val(
		rng_()
	);

	float_type cur(
		val
	);

	for(
		container::const_iterator it(
			elements_.begin()
		);
		it != elements_.end();
		++it
	)
	{
		if(
			cur <= it->prob()
		)
		{
			it->callback()();

			return;
		}

		cur -= it->prob();
	}

	throw
		random::exception(
			(
				fcppt::format(
					FCPPT_TEXT("random::actor::normalized: nothing matched! Return value was %1% and is now %2%!")
				)
				% val
				% cur
			).str()
		);
}
