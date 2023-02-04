/* -*- c++ -*- */
/*
 * Copyright 2023 Daniel Estevez <daniel@destevez.net>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "frame_counter_impl.h"
#include <gnuradio/io_signature.h>

#include <cstdint>
#include <cstring>

namespace gr {
namespace dvbgse {

frame_counter::sptr frame_counter::make(size_t itemsize, size_t frame_size)
{
    return gnuradio::make_block_sptr<frame_counter_impl>(itemsize, frame_size);
}

frame_counter_impl::frame_counter_impl(size_t itemsize, size_t frame_size)
    : gr::sync_block("frame_counter",
                     gr::io_signature::make(1, 1, itemsize),
                     gr::io_signature::make(1, 1, itemsize)),
      d_itemsize(itemsize),
      d_frame_size(frame_size),
      d_frame_message(pmt::string_to_symbol("frame_message")),
      d_nitems(0)
{
    message_port_register_out(d_frame_message);
}

frame_counter_impl::~frame_counter_impl() {}

int frame_counter_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    auto in = static_cast<const uint8_t*>(input_items[0]);
    auto out = static_cast<uint8_t*>(output_items[0]);

    std::memcpy(out, in, noutput_items * d_itemsize);
    for (d_nitems += noutput_items; d_nitems >= d_frame_size; d_nitems -= d_frame_size) {
        message_port_pub(d_frame_message, pmt::PMT_NIL);
    }

    return noutput_items;
}

} /* namespace dvbgse */
} /* namespace gr */
