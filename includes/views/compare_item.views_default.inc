<?php
/**
 * Views for the compare page.
 */


/**
 * Implements hook_views_default_views().
 */
function compare_item_views_default_views() {
  
	$instances = field_info_instances('commerce_product');//returns list of all commerce_products,their fields,field details
//	print_r($instances);

$count=0;//using this for naming the different views,pages
$bundle_name;//stores the name of the bundle to use in the filter(bundle = product)

$compare_field_name;//stores the name of the compare type field for each bundle 
$views = array();

foreach ($instances as $val) {//for getting the array of each bundle/product
	$count++;
	$compare_field_present=0;	//flag to check whether the current bundle has a field of type compare
		  // Define the shopping cart update form as a View.
		  $view = new view;
		  $view->name = 'compare_page_'.$count;
		  $view->description = 'Display the compare page.';
		  $view->tag = 'compare';
		  $view->base_table = 'commerce_product';
		  $view->human_name = 'Compare Page '.$count;
		  $view->core = 7;
		  $view->api_version = '3.0';
		  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

		//  /* Display: Defaults */
		  $handler = $view->new_display('default', 'Master', 'default');
		  $handler->display->display_options['title'] = 'Compare page '.$count;
		  $handler->display->display_options['access']['type'] = 'none';
		  $handler->display->display_options['cache']['type'] = 'none';
		  $handler->display->display_options['query']['type'] = 'views_query';
		  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
			$handler->display->display_options['exposed_form']['type'] = 'basic';
			$handler->display->display_options['pager']['type'] = 'full';
			$handler->display->display_options['pager']['options']['items_per_page'] = '10';
//			$handler->display->display_options['style_plugin'] = 'list';
			$handler->display->display_options['style_plugin'] = 'table';
			
			
			$handler->display->display_options['style_options']['override'] = 1;
			$handler->display->display_options['style_options']['sticky'] = 0;
			$handler->display->display_options['style_options']['empty_table'] = 0;
		/* Field: Commerce Product: Title */
			$handler->display->display_options['fields']['title']['id'] = 'title';
			$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
			$handler->display->display_options['fields']['title']['field'] = 'title';
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

			foreach ($val as $value) {//for getting the array of each field in the current bundle/product
	echo "FIELD NAME: ";
			  print_r($value['field_name']);
	echo "\n";
				//add a field only if its not the commerce price field or the compare type field
				if($value['field_name'] != "commerce_price" && $value['widget']['type'] != "compare_item_compare_widget") {
	echo "THE OTHER FIELD NAME: ";
				  print_r($value['field_name']);
	echo "\n";

		   		  $handler->display->display_options['fields'][$value['field_name']]['id'] = $value['field_name'];
				  	$handler->display->display_options['fields'][$value['field_name']]['table'] = 'field_data_'.$value['field_name'];
						$handler->display->display_options['fields'][$value['field_name']]['field'] = $value['field_name'];
//					$handler->display->display_options['fields'][$value['field_name']]['label'] = '';
						$handler->display->display_options['fields'][$value['field_name']]['alter']['alter_text'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['make_link'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['absolute'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['external'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['replace_spaces'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['trim_whitespace'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['nl2br'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['word_boundary'] = 1;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['ellipsis'] = 1;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['more_link'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['strip_tags'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['trim'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['alter']['html'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['element_label_colon'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['element_default_classes'] = 1;
						$handler->display->display_options['fields'][$value['field_name']]['hide_empty'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['empty_zero'] = 0;
						$handler->display->display_options['fields'][$value['field_name']]['hide_alter_empty'] = 1;
						$handler->display->display_options['fields'][$value['field_name']]['field_api_classes'] = 0;
				}
				//if field is an image setting for showing image as a thumbnail
				if($value['widget']['type'] == "image_image") {
					/* Field: Commerce Product: Image */
					$handler->display->display_options['fields'][$value['field_name']]['settings'] = array(
					  'image_style' => 'thumbnail',
					  'image_link' => 'content',
					);
				}
				//if field is compare type then set flag to true and save the name of the field to use as a filter
				if($value['widget']['type'] == "compare_item_compare_widget") {
					$compare_field_present=1;
					$compare_field_name=$value['field_name'];
//	echo "\nCOMPARE FIELD NAME:".$compare_field_name."\n";
				}
					  $bundle_name=$value['bundle'];
					  $handler->display->display_options['css_class'] = $bundle_name;
			}
			//if the current bundle/product doesnt have a compare field skip creating the view
			if($compare_field_present == 0) {
//				echo "\n**no compare field**\n";
				continue;
			}
//			echo "\nBUNDLE:$bundle_name\n";
			/* Filter criterion: Commerce Product: Type */
			$handler->display->display_options['filters']['type']['id'] = 'type';
			$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
			$handler->display->display_options['filters']['type']['field'] = 'type';
			$handler->display->display_options['filters']['type']['value'] = array(
			  $bundle_name => $bundle_name,
			);
			/* Filter criterion: Commerce Product: Comparable Allowed  */
			$column_name=$compare_field_name.'_comparable';
			$handler->display->display_options['filters'][$column_name]['id'] = $column_name;
			$handler->display->display_options['filters'][$column_name]['table'] = 'field_data_'.$compare_field_name;
			$handler->display->display_options['filters'][$column_name]['field'] = $column_name;
			$handler->display->display_options['filters'][$column_name]['operator'] = 'not empty';
	
			/* Contextual filter: Commerce Product: SKU */
			$handler->display->display_options['arguments']['sku']['id'] = 'sku';
			$handler->display->display_options['arguments']['sku']['table'] = 'commerce_product';
			$handler->display->display_options['arguments']['sku']['field'] = 'sku';
			$handler->display->display_options['arguments']['sku']['default_action'] = 'default';
			$handler->display->display_options['arguments']['sku']['default_argument_type'] = 'raw';
			$handler->display->display_options['arguments']['sku']['default_argument_options']['index'] = '2';
			$handler->display->display_options['arguments']['sku']['default_argument_skip_url'] = 1;
			$handler->display->display_options['arguments']['sku']['summary']['number_of_records'] = '0';
			$handler->display->display_options['arguments']['sku']['summary']['format'] = 'default_summary';
			$handler->display->display_options['arguments']['sku']['summary_options']['items_per_page'] = '25';
			$handler->display->display_options['arguments']['sku']['glossary'] = 0;
			$handler->display->display_options['arguments']['sku']['limit'] = '0';
			$handler->display->display_options['arguments']['sku']['transform_dash'] = 0;
			$handler->display->display_options['arguments']['sku']['break_phrase'] = 1;
			
			/* Display: Page */
		  $handler = $view->new_display('page', 'Page', 'page');
		  $handler->display->display_options['path'] = $bundle_name.'/comparepage';
		  $handler->display->display_options['menu']['type'] = 'normal';
		  $handler->display->display_options['menu']['title'] = 'Compare Page '.$bundle_name;
			$handler->display->display_options['menu']['name'] = 'main-menu';
			
			//adds a new view to the views array
			$views[$view->name] = $view;
		}
  return $views;
}














//
///**
// * Implements hook_views_default_views().
// */
//function compare_item_views_default_views() {
//  
//	$instances = field_info_instances(commerce_product);
//	print_r($instances);
////	foreach ($instances as $value) {
//////		print_r($value[field_name]);
////		if($value[field_name] != "commerce_price" && $value[widget][type] != "compare_item_compare_widget" && $value[widget][type] != "image_image") {
////			print_r($value[field_name]);
////		}		
////	}
//
////	$instances = field_info_instances(commerce_product);
////	print_r($instances);
//	//for use later---general version
////	foreach ($instances as $value) {
//////		print_r($value); 
////		foreach ($value as $val) {
////				echo "BUNDLE:";
////			print_r($val[bundle]);
////			echo ";		";
////			print_r($val[field_name]);
////				echo "\n			WIDGET:";
////		print_r($val[widget][type]);
////		echo "\n";
////		}
////	}
//
//	//foreach ($instances as $entity_type => $type_bundles) {
////    foreach ($type_bundles as $bundle => $bundle_instances) {
////      foreach ($bundle_instances as $field_namea => $name) {
//////        $field = field_info_field($field_name);
////      }
////    }
////}
////        
////	echo "\n";
////			  $bundle_query = db_select('field_data_field_compare', 'fdfc');
////			    $bundle_query->fields('fdfc', array('bundle'));
////			    $bundle = $bundle_query->execute()->fetchAll();
////			    print_r($bundle);
//			    
////			    foreach ($bundle as $value) {
////			    	echo $value->bundle;
////			    
////				
////				$field_name_query = db_select('field_config_instance', 'fci');
////			    $field_name_query->fields('fci', array('field_name'));
////			    $field_name_query->condition('bundle', $value->bundle, '=');
////			    $field_names = $field_name_query->execute()->fetchAll();
//////			  print_r($field_names);
////
////			    foreach ($field_names as $value) {
////			    	echo $value->field_name."    ";
////			    }
////			    echo "\n";
////			    }
////    
//    $views = array();
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
////  /* Display: Defaults */
//  $handler = $view->new_display('default', 'Master', 'default');
//  $handler->display->display_options['title'] = 'Compare page';
//  $handler->display->display_options['access']['type'] = 'none';
//  $handler->display->display_options['cache']['type'] = 'none';
//  $handler->display->display_options['query']['type'] = 'views_query';
//  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
//  $handler->display->display_options['exposed_form']['type'] = 'basic';
//	$handler->display->display_options['pager']['type'] = 'full';
//	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
//	$handler->display->display_options['style_plugin'] = 'list';
////	$handler->display->display_options['style_plugin'] = 'table';
////	$handler->display->display_options['style_options']['columns'] = array(
////	  'title' => 'title',
////		'field_pd_color' => 'field_pd_color',
////	  'field_pd_image' => 'field_pd_image',
////	  'field_pd_size' => 'field_pd_size',
////);
////	$handler->display->display_options['style_options']['default'] = '-1';
////	$handler->display->display_options['style_options']['info'] = array(
////	  'title' => array(
////	    'sortable' => 0,
////	    'default_sort_order' => 'asc',
////	    'align' => '',
////	    'separator' => '',
////	    'empty_column' => 0,
////	  ),
////		'field_pd_color' => array(
////	    'sortable' => 0,
////	    'default_sort_order' => 'asc',
////	    'align' => '',
////	    'separator' => '',
////	    'empty_column' => 0,
////	  ),
////	  'field_pd_image' => array(
////	    'sortable' => 0,
////	    'default_sort_order' => 'asc',
////	    'align' => '',
////	    'separator' => '',
////	    'empty_column' => 0,
////	  ),
////	  'field_pd_size' => array(
////	    'sortable' => 0,
////	    'default_sort_order' => 'asc',
////	    'align' => '',
////	    'separator' => '',
////	    'empty_column' => 0,
////	  ),
////	);
//	$handler->display->display_options['style_options']['override'] = 1;
//	$handler->display->display_options['style_options']['sticky'] = 0;
//	$handler->display->display_options['style_options']['empty_table'] = 0;
///* Field: Commerce Product: Title */
//	$handler->display->display_options['fields']['title']['id'] = 'title';
//	$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
//	$handler->display->display_options['fields']['title']['field'] = 'title';
////	$handler->display->display_options['fields']['title']['label'] = '';
//	$handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['external'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
//	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
//	$handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['trim'] = 0;
//	$handler->display->display_options['fields']['title']['alter']['html'] = 0;
//	$handler->display->display_options['fields']['title']['element_label_colon'] = 0;
//	$handler->display->display_options['fields']['title']['element_default_classes'] = 1;
//	$handler->display->display_options['fields']['title']['hide_empty'] = 0;
//	$handler->display->display_options['fields']['title']['empty_zero'] = 0;
//	$handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
//	$handler->display->display_options['fields']['title']['link_to_product'] = 0;
//	
////	foreach ($bundle as $value) {
////		
////		$field_name_query = db_select('field_config_instance', 'fci');
////			    $field_name_query->fields('fci', array('field_name'));
////			    $field_name_query->condition('bundle', $value->bundle, '=');
////			    $field_names = $field_name_query->execute()->fetchAll();
////
////			    foreach ($field_names as $value) {
////			    	if($value->field_name != "commerce_price" && $value->field_name != "field_compare" && $value->field_name != "field_camera_image" && $value->field_name != "field_pd_image") {
////			    		echo $value->field_name.", ";
////			    	}
////			    }
////			    	echo "\n";
////	}
////
//$bundle_name;
//	foreach ($instances as $val) {
//		print_r($value); 
//		foreach ($val as $value) {
//			if($value[field_name] != "commerce_price" && $value[widget][type] != "compare_item_compare_widget" && $value[widget][type] != "image_image") {
//				print_r($value[field_name]);
//			
//			  		$handler->display->display_options['fields'][$value[field_name]]['id'] = $value[field_name];
//						$handler->display->display_options['fields'][$value[field_name]]['table'] = 'field_data_'.$value[field_name];
//						$handler->display->display_options['fields'][$value[field_name]]['field'] = $value[field_name];
//					//	$handler->display->display_options['fields']['field_pd_color']['label'] = '';
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['alter_text'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['make_link'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['absolute'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['external'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['replace_spaces'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['trim_whitespace'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['nl2br'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['word_boundary'] = 1;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['ellipsis'] = 1;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['more_link'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['strip_tags'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['trim'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['alter']['html'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['element_label_colon'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['element_default_classes'] = 1;
//						$handler->display->display_options['fields'][$value[field_name]]['hide_empty'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['empty_zero'] = 0;
//						$handler->display->display_options['fields'][$value[field_name]]['hide_alter_empty'] = 1;
//						$handler->display->display_options['fields'][$value[field_name]]['field_api_classes'] = 0;
//			    	
//			    }
//			    $bundle_name=$value[bundle];
//			    echo "\nBUNDLE:$bundle_name\n";
//		}
////				/* Filter criterion: Commerce Product: Type */
////			$handler->display->display_options['filters']['type']['id'] = 'type';
////			$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
////			$handler->display->display_options['filters']['type']['field'] = 'type';
////			$handler->display->display_options['filters']['type']['value'] = array(
////			  $bundle_name => $bundle_name,
////			);
//	}
//
//
//
////foreach ($instances as $value) {
//////		print_r($value[field_name]);
////		if($value[field_name] != "commerce_price" && $value[widget][type] != "compare_item_compare_widget" && $value[widget][type] != "image_image") {
////			print_r($value[field_name]);
////			
////			  		$handler->display->display_options['fields'][$value[field_name]]['id'] = $value[field_name];
////						$handler->display->display_options['fields'][$value[field_name]]['table'] = 'field_data_'.$value[field_name];
////						$handler->display->display_options['fields'][$value[field_name]]['field'] = $value[field_name];
////					//	$handler->display->display_options['fields']['field_pd_color']['label'] = '';
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['alter_text'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['make_link'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['absolute'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['external'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['replace_spaces'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['trim_whitespace'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['nl2br'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['word_boundary'] = 1;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['ellipsis'] = 1;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['more_link'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['strip_tags'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['trim'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['alter']['html'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['element_label_colon'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['element_default_classes'] = 1;
////						$handler->display->display_options['fields'][$value[field_name]]['hide_empty'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['empty_zero'] = 0;
////						$handler->display->display_options['fields'][$value[field_name]]['hide_alter_empty'] = 1;
////						$handler->display->display_options['fields'][$value[field_name]]['field_api_classes'] = 0;
////			    	}
////			    	echo "\n";
////			    }
////////			    echo "\n";
//////	}
////				/* Filter criterion: Commerce Product: Type */
////			$handler->display->display_options['filters']['type']['id'] = 'type';
////			$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
////			$handler->display->display_options['filters']['type']['field'] = 'type';
////			$handler->display->display_options['filters']['type']['value'] = array(
////			  'pen_drives' => 'pen_drives',
////			);
//
//	
////	/* Field: Commerce Product: Color */
////	$handler->display->display_options['fields']['field_pd_color']['id'] = 'field_pd_color';
////	$handler->display->display_options['fields']['field_pd_color']['table'] = 'field_data_field_pd_color';
////	$handler->display->display_options['fields']['field_pd_color']['field'] = 'field_pd_color';
//////	$handler->display->display_options['fields']['field_pd_color']['label'] = '';
////	$handler->display->display_options['fields']['field_pd_color']['alter']['alter_text'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['make_link'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['absolute'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['external'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['replace_spaces'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['trim_whitespace'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['nl2br'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['word_boundary'] = 1;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['ellipsis'] = 1;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['more_link'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['strip_tags'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['trim'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['alter']['html'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['element_label_colon'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['element_default_classes'] = 1;
////	$handler->display->display_options['fields']['field_pd_color']['hide_empty'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['empty_zero'] = 0;
////	$handler->display->display_options['fields']['field_pd_color']['hide_alter_empty'] = 1;
////	$handler->display->display_options['fields']['field_pd_color']['field_api_classes'] = 0;
////	/* Field: Commerce Product: Image */
////	$handler->display->display_options['fields']['field_pd_image']['id'] = 'field_pd_image';
////	$handler->display->display_options['fields']['field_pd_image']['table'] = 'field_data_field_pd_image';
////	$handler->display->display_options['fields']['field_pd_image']['field'] = 'field_pd_image';
//////	$handler->display->display_options['fields']['field_pd_image']['label'] = '';
////	$handler->display->display_options['fields']['field_pd_image']['alter']['alter_text'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['make_link'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['absolute'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['external'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['replace_spaces'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['trim_whitespace'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['nl2br'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['word_boundary'] = 1;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['ellipsis'] = 1;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['more_link'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['strip_tags'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['trim'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['alter']['html'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['element_label_colon'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['element_default_classes'] = 1;
////	$handler->display->display_options['fields']['field_pd_image']['hide_empty'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['empty_zero'] = 0;
////	$handler->display->display_options['fields']['field_pd_image']['hide_alter_empty'] = 1;
////	$handler->display->display_options['fields']['field_pd_image']['click_sort_column'] = 'fid';
////	$handler->display->display_options['fields']['field_pd_image']['settings'] = array(
////	  'image_style' => 'thumbnail',
////	  'image_link' => 'content',
////	);
////	$handler->display->display_options['fields']['field_pd_image']['field_api_classes'] = 0;
////	/* Field: Commerce Product: Size */
////	$handler->display->display_options['fields']['field_pd_size']['id'] = 'field_pd_size';
////	$handler->display->display_options['fields']['field_pd_size']['table'] = 'field_data_field_pd_size';
////	$handler->display->display_options['fields']['field_pd_size']['field'] = 'field_pd_size';
//////	$handler->display->display_options['fields']['field_pd_size']['label'] = '';
////	$handler->display->display_options['fields']['field_pd_size']['alter']['alter_text'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['make_link'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['absolute'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['external'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['replace_spaces'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['trim_whitespace'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['nl2br'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['word_boundary'] = 1;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['ellipsis'] = 1;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['more_link'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['strip_tags'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['trim'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['alter']['html'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['element_label_colon'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['element_default_classes'] = 1;
////	$handler->display->display_options['fields']['field_pd_size']['hide_empty'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['empty_zero'] = 0;
////	$handler->display->display_options['fields']['field_pd_size']['hide_alter_empty'] = 1;
////	$handler->display->display_options['fields']['field_pd_size']['field_api_classes'] = 0;
////	
////	/* Filter criterion: Commerce Product: Type */
////	$handler->display->display_options['filters']['type']['id'] = 'type';
////	$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
////	$handler->display->display_options['filters']['type']['field'] = 'type';
////	$handler->display->display_options['filters']['type']['value'] = array(
////	  'pen_drives' => 'pen_drives',
////	);
//
////	/* Display: Page */
//  $handler = $view->new_display('page', 'Page', 'page');
//  $handler->display->display_options['path'] = 'comparepage';
//  $handler->display->display_options['menu']['type'] = 'normal';
//  $handler->display->display_options['menu']['title'] = 'Compare Page';
//	$handler->display->display_options['menu']['name'] = 'main-menu';
////	
//    
//    
//    
//    
//    
//    
//    
//    
//    
////    
////    
////    
////	
////
////  // Define the shopping cart update form as a View.
////  $view = new view;
////  $view->name = 'compare_page';
////  $view->description = 'Display the compare page.';
////  $view->tag = 'compare';
////  $view->base_table = 'commerce_product';
////  $view->human_name = 'Compare Page';
////  $view->core = 7;
////  $view->api_version = '3.0';
////  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
////  
////  /* Display: Defaults */
////  $handler = $view->new_display('default', 'Master', 'default');
////  $handler->display->display_options['title'] = 'Compare page';
////  $handler->display->display_options['access']['type'] = 'none';
////  $handler->display->display_options['cache']['type'] = 'none';
////  $handler->display->display_options['query']['type'] = 'views_query';
////  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
////  $handler->display->display_options['exposed_form']['type'] = 'basic';
////  $handler->display->display_options['pager']['type'] = 'full';
//////  $handler->display->display_options['style_plugin'] = 'list';
////	$handler->display->display_options['style_plugin'] = 'table';
////  $handler->display->display_options['style_options']['columns'] = array(
////    'title' => 'title',
//////    'field_pd_size_value' => 'field_pd_size_value',//Testing with a specific custom field right now.
//////    'quantity' => 'quantity',
//////    'commerce_total' => 'commerce_total',
////  );
////  
//////  $handler->display->display_options['row_plugin'] = 'node';
//
////	$handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
////  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_product';
////  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
////  
////  /* Field: Commerce Product: Title */
////  $handler->display->display_options['fields']['title']['id'] = 'title';
////  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
////  $handler->display->display_options['fields']['title']['field'] = 'title';
////  $handler->display->display_options['fields']['title']['link_to_product'] = 1;
////
////  /* Field: Commerce Product: Size *///Testing with a specific custom field right now.
//////  $handler->display->display_options['fields']['field_pd_size_value']['id'] = 'field_pd_size_value';
//////  $handler->display->display_options['fields']['field_pd_size_value']['table'] = 'field_data_field_pd_size';
//////  $handler->display->display_options['fields']['field_pd_size_value']['field'] = 'field_pd_size_value';
//////  $handler->display->display_options['fields']['field_pd_size_value']['link_to_product'] = 1;
////  
////  /* Display: Page */
////  $handler = $view->new_display('page', 'Page', 'page');
////  $handler->display->display_options['path'] = 'comparepage';
//////  $handler->display->display_options['menu']['type'] = 'normal';
//////  $handler->display->display_options['menu']['title'] = 'CompareP';
//////  $handler->display->display_options['menu']['weight'] = '0';
//
//  $views[$view->name] = $view;
////print_r($views);  
//  return $views;
//}

