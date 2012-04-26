<?php

/**
 * Theme implementation to display the compare cart.

 * Available variables:
 * - $image_paths: The the base path for the site.
 */
?>

<div id="compare_cart">
  <?php //echo($image_paths); ?>
  <table id="compare-cart-table">
  	<tr class="compare-cart-items-to-compare">
  		<td name="compare_item" id="compare_item">
<!--  			<div class="div_image compare-product compare-product-image">-->
<!--  				<img src="<?php //echo($image_paths); ?>sites/all/modules/compare_item/images/add_item.jpg" class="image" height="50px" width="50px" />-->
<!--  			</div>-->
  			<div class="remove_item compare-product-remove"></div>
  			<div class="compare-product-title compare-product"></div>
 	 		</td>
  		<td name="compare_item" id="compare_item">
<!--  			<div class="div_image compare-product compare-product-image">-->
<!--  				<img src="<?php //echo($image_paths); ?>sites/all/modules/compare_item/images/add_item.jpg" class="image" height="50px" width="50px" />-->
<!--  			</div>-->
  			<div class="remove_item compare-product-remove"></div>
  			<div class="compare-product-title compare-product"></div>
  		</td>
  		<td name="compare_item" id="compare_item">
<!--  			<div class="div_image compare-product compare-product-image">-->
<!--  				<img src="<?php //echo($image_paths); ?>sites/all/modules/compare_item/images/add_item.jpg" class="image" height="50px" width="50px" />-->
<!--  			</div>-->
  			<div class="remove_item compare-product-remove"></div>
  			<div class="compare-product-title compare-product"></div>
  		</td>
  		<td name="compare_item" id="compare_item">
<!--  			<div class="div_image compare-product compare-product-image">-->
<!--  				<img src="<?php //echo($image_paths); ?>sites/all/modules/compare_item/images/add_item.jpg" class="image" height="50px" width="50px" />-->
<!--  			</div>-->
  			<div class="remove_item compare-product-remove"></div>
  			<div class="compare-product-title compare-product"></div>
  		</td>
  	</tr>
  	
  	<tr>
  		<td colspan="4">
	  		<div id="compare_cart_options" class="div_image">
		  		<a id="aclose" class="compare_cart_options_css compare_cart_close">Close</a>
		  		<label class="compare_cart_options_css">|</label>
		  		<a id="aclearlist" class="compare_cart_options_css compare_cart_clear">Clear list</a>
		  		<button id="btn_compare" class="compare_cart_options_css compare_cart_compare_button">Compare</button>
				</div>
			</td>
	  </tr>
  </table>
  
</div>