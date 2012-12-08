//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_RAW_CONTAINER_SOURCE_IMPL_HPP_INCLUDED
#define FCPPT_IO_RAW_CONTAINER_SOURCE_IMPL_HPP_INCLUDED

#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/io/raw_container_source_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template<typename Container>
template<typename Iterator>
fcppt::io::raw_container_source<Container>::raw_container_source(
	Iterator const begin,
	Iterator const end)
:
	chars_(
		fcppt::make_shared_ptr<container>(
			begin,
			end)),
	pos_(
		chars_->begin())
{
}

template<typename Container>
fcppt::io::raw_container_source<Container>::raw_container_source(
	raw_container_source const &_other
)
:
	chars_(
		_other.chars_
	),
	pos_(
		_other.pos_
	)
{
}

template<typename Container>
fcppt::io::raw_container_source<Container>::~raw_container_source()
{
}

template<typename Container>
std::streamsize
fcppt::io::raw_container_source<Container>::read(
	char *target,
	std::streamsize const n)
{
	typedef typename std::iterator_traits<
		const_iterator
	>::difference_type difference_type;

	difference_type const result =
		std::min(
			static_cast<
				difference_type
			>(
				n),
			std::distance(
				pos_,
				chars_->cend()));

	// EOF
	if (result == 0u)
		return -1;

	const_iterator const new_pos =
		std::next(
			pos_,
			result);

	std::copy(
		pos_,
		new_pos,
		target);

	pos_ = new_pos;
	return result;
}

template<typename Container>
std::streampos
fcppt::io::raw_container_source<Container>::seek(
	boost::iostreams::stream_offset const off,
	std::ios_base::seekdir const way)
{
	switch (way)
	{
		case std::ios_base::beg:
			pos_ =
				std::next(
					chars_->cbegin(),
					off);
			break;
		case std::ios_base::cur:
			pos_ =
				std::next(
					pos_,
					off);
			break;
		case std::ios_base::end:
			pos_ =
				std::prev(
					chars_->cend(),
					off);
			break;
		default: break;
	}
	return
		static_cast<
			std::streampos
		>(
			std::distance(
				chars_->cbegin(),
				pos_));
}

#endif
