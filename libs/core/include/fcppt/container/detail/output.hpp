//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_OUTPUT_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_OUTPUT_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace detail
{

template<
	typename Container
>
class output
{
public:
	explicit
	output(
		Container const &_container
	)
	:
		container_{
			_container
		}
	{
	}

	[[nodiscard]]
	Container const &
	container() const
	{
		return
			this->container_.get();
	}
private:
	fcppt::reference<
		Container const
	> container_;
};

template<
	typename Container,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::container::detail::output<
		Container
	> const &_output
)
{
	_stream
		<<
		_stream.widen(
			'['
		);

	using
	const_iterator
	=
	typename
	Container::const_iterator;

	auto const end(
		_output.container().end()
	);

	for(
		const_iterator it{
			_output.container().begin()
		};
		it != end;
		++it
	)
	{
		_stream
			<<
			*it;

		if(
			// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
			std::next(
				it
			)
			!=
			end
		)
		{
			_stream
				<<
				_stream.widen(
					','
				);
		}
	}

	_stream
		<<
		_stream.widen(
			']'
		);

	return
		_stream;
}

}
}
}

#endif
