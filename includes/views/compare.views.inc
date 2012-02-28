<?php 
/**
 * 
 */
  function compare_views_data_alter(&$data) {
  $data['views']['view'] = array(
    'title' => t('View'),
    'help' => t('Embed a view as field. This can cause slow performance, so enable some caching.'),
    'field' => array(
      '#type' => 'checkbox',
      '#title' => t('Add a checkbox to compare'),
      'handler' => 'compare_handler_field_view',
    ),
    'area' => array(
      'help' => t('Embed a view in an Area, such as Header, Footer, Empty Text.'),
      'handler' => 'compare_handler_field_view',
    ),
  );
}
