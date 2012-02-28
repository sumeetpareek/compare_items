<?php
  $image_id = $_GET['id'];
  $result = db_select('file_usage', 'fu')
        ->fields('fid')
        ->condition('id', $image_id, '=')
        ->execute();
        
  $image = db_select('file_managed', 'fm')
        ->fields('uri')
        ->condition('fid', $result, '=')
        ->execute();
        
  return $image;
?>