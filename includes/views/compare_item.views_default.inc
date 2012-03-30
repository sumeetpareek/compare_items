<?php
/**
 * Views for the compare page.
 */

/**
 * Implements hook_views_default_views().
 */
function compare_item_views_default_views() {
  
  $field_name_query = db_select('field_config_instance', 'fci');
    $field_name_query->fields('fci', array('field_name'));
    $field_name_query->condition('bundle', 'pen_drives', '=');
    $field_names = $field_name_query->execute()->fetchAll();
//  print_r($field_names);
  
    $views = array();
    
  // Define the shopping cart update form as a View.
  $view = new view;
  $view->name = 'compare_page';
  $view->description = 'Display the compare page.';
  $view->tag = 'compare';
  $view->base_table = 'commerce_product';
  $view->human_name = 'Compare Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

//  /* Display: Defaults */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Compare page';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'table';
	$handler->display->display_options['style_options']['columns'] = array(
	  'field_pd_color' => 'field_pd_color',
	  'field_pd_image' => 'field_pd_image',
	  'field_pd_size' => 'field_pd_size',
	  'title' => 'title',
	);
	$handler->display->display_options['style_options']['default'] = '-1';
	$handler->display->display_options['style_options']['info'] = array(
	  'field_pd_color' => array(
	    'sortable' => 0,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'field_pd_image' => array(
	    'sortable' => 0,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'field_pd_size' => array(
	    'sortable' => 0,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'title' => array(
	    'sortable' => 0,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	);
	$handler->display->display_options['style_options']['override'] = 1;
	$handler->display->display_options['style_options']['sticky'] = 0;
	$handler->display->display_options['style_options']['empty_table'] = 0;
	/* Field: Commerce Product: Color */
	$handler->display->display_options['fields']['field_pd_color']['id'] = 'field_pd_color';
	$handler->display->display_options['fields']['field_pd_color']['table'] = 'field_data_field_pd_color';
	$handler->display->display_options['fields']['field_pd_color']['field'] = 'field_pd_color';
	$handler->display->display_options['fields']['field_pd_color']['label'] = '';
	$handler->display->display_options['fields']['field_pd_color']['alter']['alter_text'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['make_link'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['absolute'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['external'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['replace_spaces'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['trim_whitespace'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['nl2br'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['word_boundary'] = 1;
	$handler->display->display_options['fields']['field_pd_color']['alter']['ellipsis'] = 1;
	$handler->display->display_options['fields']['field_pd_color']['alter']['more_link'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['strip_tags'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['trim'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['alter']['html'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['element_label_colon'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['element_default_classes'] = 1;
	$handler->display->display_options['fields']['field_pd_color']['hide_empty'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['empty_zero'] = 0;
	$handler->display->display_options['fields']['field_pd_color']['hide_alter_empty'] = 1;
	$handler->display->display_options['fields']['field_pd_color']['field_api_classes'] = 0;
	/* Field: Commerce Product: Image */
	$handler->display->display_options['fields']['field_pd_image']['id'] = 'field_pd_image';
	$handler->display->display_options['fields']['field_pd_image']['table'] = 'field_data_field_pd_image';
	$handler->display->display_options['fields']['field_pd_image']['field'] = 'field_pd_image';
	$handler->display->display_options['fields']['field_pd_image']['label'] = '';
	$handler->display->display_options['fields']['field_pd_image']['alter']['alter_text'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['make_link'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['absolute'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['external'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['replace_spaces'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['trim_whitespace'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['nl2br'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['word_boundary'] = 1;
	$handler->display->display_options['fields']['field_pd_image']['alter']['ellipsis'] = 1;
	$handler->display->display_options['fields']['field_pd_image']['alter']['more_link'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['strip_tags'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['trim'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['alter']['html'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['element_label_colon'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['element_default_classes'] = 1;
	$handler->display->display_options['fields']['field_pd_image']['hide_empty'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['empty_zero'] = 0;
	$handler->display->display_options['fields']['field_pd_image']['hide_alter_empty'] = 1;
	$handler->display->display_options['fields']['field_pd_image']['click_sort_column'] = 'fid';
	$handler->display->display_options['fields']['field_pd_image']['settings'] = array(
	  'image_style' => 'thumbnail',
	  'image_link' => 'content',
	);
	$handler->display->display_options['fields']['field_pd_image']['field_api_classes'] = 0;
	/* Field: Commerce Product: Size */
	$handler->display->display_options['fields']['field_pd_size']['id'] = 'field_pd_size';
	$handler->display->display_options['fields']['field_pd_size']['table'] = 'field_data_field_pd_size';
	$handler->display->display_options['fields']['field_pd_size']['field'] = 'field_pd_size';
	$handler->display->display_options['fields']['field_pd_size']['label'] = '';
	$handler->display->display_options['fields']['field_pd_size']['alter']['alter_text'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['make_link'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['absolute'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['external'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['replace_spaces'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['trim_whitespace'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['nl2br'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['word_boundary'] = 1;
	$handler->display->display_options['fields']['field_pd_size']['alter']['ellipsis'] = 1;
	$handler->display->display_options['fields']['field_pd_size']['alter']['more_link'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['strip_tags'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['trim'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['alter']['html'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['element_label_colon'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['element_default_classes'] = 1;
	$handler->display->display_options['fields']['field_pd_size']['hide_empty'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['empty_zero'] = 0;
	$handler->display->display_options['fields']['field_pd_size']['hide_alter_empty'] = 1;
	$handler->display->display_options['fields']['field_pd_size']['field_api_classes'] = 0;
	/* Field: Commerce Product: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
	$handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
	$handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
	$handler->display->display_options['fields']['title']['alter']['external'] = 0;
	$handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
	$handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
	$handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
	$handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
	$handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
	$handler->display->display_options['fields']['title']['alter']['trim'] = 0;
	$handler->display->display_options['fields']['title']['alter']['html'] = 0;
	$handler->display->display_options['fields']['title']['element_label_colon'] = 0;
	$handler->display->display_options['fields']['title']['element_default_classes'] = 1;
	$handler->display->display_options['fields']['title']['hide_empty'] = 0;
	$handler->display->display_options['fields']['title']['empty_zero'] = 0;
	$handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
	$handler->display->display_options['fields']['title']['link_to_product'] = 0;
	/* Filter criterion: Commerce Product: Type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
	  'pen_drives' => 'pen_drives',
	);

	/* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'comparepage';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Compare Page';
	$handler->display->display_options['menu']['name'] = 'main-menu';
	
    
    
    
    
    
    
    
    
    
//    
//    
//    
//	
//
//  // Define the shopping cart update form as a View.
//  $view = new view;
//  $view->name = 'compare_page';
//  $view->description = 'Display the compare page.';
//  $view->tag = 'compare';
//  $view->base_table = 'commerce_product';
//  $view->human_name = 'Compare Page';
//  $view->core = 7;
//  $view->api_version = '3.0';
//  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
//  
//  /* Display: Defaults */
//  $handler = $view->new_display('default', 'Master', 'default');
//  $handler->display->display_options['title'] = 'Compare page';
//  $handler->display->display_options['access']['type'] = 'none';
//  $handler->display->display_options['cache']['type'] = 'none';
//  $handler->display->display_options['query']['type'] = 'views_query';
//  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
//  $handler->display->display_options['exposed_form']['type'] = 'basic';
//  $handler->display->display_options['pager']['type'] = 'full';
////  $handler->display->display_options['style_plugin'] = 'list';
//	$handler->display->display_options['style_plugin'] = 'table';
//  $handler->display->display_options['style_options']['columns'] = array(
//    'title' => 'title',
////    'field_pd_size_value' => 'field_pd_size_value',//Testing with a specific custom field right now.
////    'quantity' => 'quantity',
////    'commerce_total' => 'commerce_total',
//  );
//  
////  $handler->display->display_options['row_plugin'] = 'node';

//	$handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
//  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_product';
//  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
//  
//  /* Field: Commerce Product: Title */
//  $handler->display->display_options['fields']['title']['id'] = 'title';
//  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
//  $handler->display->display_options['fields']['title']['field'] = 'title';
//  $handler->display->display_options['fields']['title']['link_to_product'] = 1;
//
//  /* Field: Commerce Product: Size *///Testing with a specific custom field right now.
////  $handler->display->display_options['fields']['field_pd_size_value']['id'] = 'field_pd_size_value';
////  $handler->display->display_options['fields']['field_pd_size_value']['table'] = 'field_data_field_pd_size';
////  $handler->display->display_options['fields']['field_pd_size_value']['field'] = 'field_pd_size_value';
////  $handler->display->display_options['fields']['field_pd_size_value']['link_to_product'] = 1;
//  
//  /* Display: Page */
//  $handler = $view->new_display('page', 'Page', 'page');
//  $handler->display->display_options['path'] = 'comparepage';
////  $handler->display->display_options['menu']['type'] = 'normal';
////  $handler->display->display_options['menu']['title'] = 'CompareP';
////  $handler->display->display_options['menu']['weight'] = '0';

  $views[$view->name] = $view;
//print_r($views);  
  return $views;
}