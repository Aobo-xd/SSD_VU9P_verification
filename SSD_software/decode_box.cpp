float prior_width = prior_bbox.xmax() - prior_bbox.xmin();
CHECK_GT(prior_width, 0);
float prior_height = prior_bbox.ymax() - prior_bbox.ymin();
CHECK_GT(prior_height, 0);


decode_bbox->set_xmin(
      int(prior_bbox.xmin() + int((1.0/16+1.0/32+1.0/128) * ((int)(bbox.xmin() * prior_width)>>4))));
decode_bbox->set_ymin(
      int(prior_bbox.ymin() + int((1.0/16+1.0/32+1.0/128) * ((int)(bbox.ymin() * prior_height)>>4))));
decode_bbox->set_xmax(
      int(prior_bbox.xmax() + int((1.0/8+1.0/16+1.0/64) * ((int)(bbox.xmax() * prior_width)>>4))));
decode_bbox->set_ymax(
      int(prior_bbox.ymax() + int((1.0/8+1.0/16+1.0/64) * ((int)(bbox.ymax() * prior_height)>>4))));
