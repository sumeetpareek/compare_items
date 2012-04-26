(function($)  {
	function comparefunction(context)  {
			var checkbox_id;
			var compare_count = 0;
			var product_type = null;
			
//			var datathis = JSON.parse($.cookie("compare_item_cookie_single"));
//			alert("sku= "+datathis.sku+"\ncount= "+datathis.count+"\nproduct= "+datathis.product);
			
			
//			compare_item_cookie = $.cookie("compare_item_cookie") ? $.cookie("compare_item_cookie").split(',') : new Array();
			document.getElementById("btn_compare").disabled = true;
			$("#compare_cart").hide();
//			var product_class_list = $(".content .view-display-id-page").attr("class");
//			var product_class_list_array = product_class_list.split(" ");
//			var checkbox_id;
//			
////			alert(product_class_list_array[4]);
//			$("#compare_cart").attr("class",product_class_list_array[4]);
//			$(".compare").each(function(){
//				checkbox_id = $(this).attr("id");
////				alert("Checkbox id"+checkbox_id);
//				$("#"+checkbox_id).parents("div.views-field").attr("id",checkbox_id);
//			});
////			alert($("."+product_class_list_array[4]+" .views-field-title").attr("class"));
//			$("."+product_class_list_array[4]+" .views-field-title").attr("id",checkbox_id);
			
			
			
			
			if($.cookie("compare_item_cookie_single") != null) {
				update_cart_on_refresh();
//				compare_item_cookie_single = JSON.parse($.cookie("compare_item_cookie_single"));
//				product_sku = compare_item_cookie_single.sku;
//				count = compare_item_cookie_single.count;
//				compare_product_type = compare_item_cookie_single.product;
//				
//				compare_count = parseInt(count);
//				
//				product_sku_list = product_sku.split(',');
//				
//				btn_compare_check_enabled();
////				alert("Already set cookie is: "+product_sku_list);
//				$.each(product_sku_list,function(index) {	
//							alert(product_sku_list[index]);
//							$(".compare-checkbox#"+product_sku_list[index]).attr('checked', true);
//							get_item_image(product_sku_list[index],index+1,compare_product_type);
//					}
//				);
			}
//			
			
			function update_cart_on_refresh(){
				$("#compare_cart").slideDown(500, function(){
					$(this).css("display", "static");
					$(this).css("position", "relative");
					$(this).css("top", "25%");
				});	
				
				compare_item_cookie_single = JSON.parse($.cookie("compare_item_cookie_single"));
				product_sku = compare_item_cookie_single.sku;
				count = compare_item_cookie_single.count;
				compare_product_type = compare_item_cookie_single.product;
				
				compare_count = parseInt(count);
				
				product_sku_list = product_sku.split(',');
				
				btn_compare_check_enabled();
//				alert("Already set cookie is: "+product_sku_list);
				$.each(product_sku_list,function(index) {	
							alert(product_sku_list[index]);
							$(".compare-checkbox#"+product_sku_list[index]).attr('checked', true);
							get_item_image(product_sku_list[index],index+1,compare_product_type);
					}
				);
			}
			
			function get_item_image(id,compare_count,product_type) {
				alert("id= "+id+"\ncompare_count= "+compare_count+"\nproduct class= "+product_type);
				$.ajax({
					type: "POST",
					url: Drupal.settings.basePath + '/compare_item_get_image',
					dataType: 'json',
					data: "id=" + encodeURI(id),
					error: function(jqXHR, textStatus, errorThrown){
						alert("THE ERROR IS: "+errorThrown);
					},
					success: function(result){
//					alert("Result= "+result);
//							alert("RESULT: "+result["title"]);
							var product_title = result["title"];
//							var product_image = result["image_url"];
//							alert("***"+Drupal.settings.basePath);
							var remove_item = Drupal.settings.basePath+'sites/all/modules/compare_item/images/remove.gif';
//							alert("Product title = "+product_title+"\nProduct image url = "+product_image);
							
//							compare_count = parseInt($.cookie("compare_count_cookie"));
//							alert("The cookie count retrieved is = "+compare_count);
							
//							$('td#' + id + " span.compare-product-title").html(product_title);
//							$('td#' + id + " div.compare-product-image img").attr('src', product_image);
//ADD THE TITLE, IMAGE, REMOVE BUTTON FOR THE ITEM ADDED							
							$('table#compare-cart-table td:nth-child('+compare_count+') div.compare-product-title').html(product_title);
//							$('table#compare-cart-table td:nth-child('+compare_count+') div.compare-product-image img').attr('src', product_image);
							$('table#compare-cart-table td:nth-child('+compare_count+') div.compare-product-remove').html('<img src="'+remove_item+'"/>');
							$('table#compare-cart-table tr:first-child td:nth-child('+compare_count+')').attr("id",id);
							$('table#compare-cart-table').attr("class",product_type);
							$('table#compare-cart-table tr:first-child td:nth-child('+compare_count+')').css('background-color','black');
							
//							var title_list = $("#compare_cart .compare-product-title");
//							alert(title_list);
//							var title_list_to_array = jQuery.makeArray(title_list);
//							title_list_to_array[compare_compare_count-1].innerHTML=result["title"];
//							
////								var image_list = $("#compare_cart .compare-product-image");
////								alert(image_list);
////								var image_list_to_array = jQuery.makeArray(image_list);
////								alert(image_list_to_array);
//							
//							var image_element = document.getElementById(id).getElementsByTagName("img");
//							var span_element = document.getElementById(id).getElementsByTagName("span");
//							image_element[0].setAttribute("src",result["image_url"]);
//							span_element[0].setAttribute("title", "Remove");
//							span_element[0].innerHTML = "<img src='/compare/sites/all/modules/compare_item/images/remove.gif' />";
					}
				});
			}
			
			
			function remove_compare_cart_item(id){
				compare_item_cookie_single = JSON.parse($.cookie("compare_item_cookie_single"));
				product_sku = compare_item_cookie_single.sku;
				count = compare_item_cookie_single.count;
				compare_product_type = compare_item_cookie_single.product;
				
				compare_cart_table_class = $('table#compare-cart-table').attr("class");
				alert("compare_product_type = "+compare_product_type+"\ncompare_cart_table_class = "+compare_cart_table_class);
				
				if(compare_cart_table_class == compare_product_type){				
					$('table#compare-cart-table tr:first-child td#'+id).remove();
					$('table#compare-cart-table tr:first-child td:nth-child(3)').after(
						"<td name='compare_item' id='compare_item'>" +
	//					"	<div class='div_image compare-product compare-product-image'>" +
	//					"		<img src='/compare/sites/all/modules/compare_item/images/add_item.jpg' class='image' height='50px' width='50px' />" +
	//					"	</div>" +
						"	<div class='remove_item compare-product-remove'></div>" +
						"	<div class='compare-product-title compare-product'></div>" +
						"</td>"
					);

//Removing the current id from cookie
				
					product_sku_list = product_sku.split(',');
					
					alert("LIST before removal = "+product_sku_list+"\nProduct to remove = "+id);
					
					$.each(product_sku_list,function(index) {
								alert("This value is: "+product_sku_list[index]);
								if (product_sku_list[index] == id) {
									product_sku_list.splice(index,1);
									
									alert("LIST after removal = "+product_sku_list+"\nProduct to remove = "+id);
					//DECREMENTING THE COUNT VALUE BY 1
									compare_count = parseInt(count);
					//			alert("The count was = "+compare_count);
									compare_count--;
									
									compare_item_cookie_single.sku = product_sku_list.join(',');
									compare_item_cookie_single.count = compare_count;				
					
									$.cookie("compare_item_cookie_single",JSON.stringify(compare_item_cookie_single),{ path: '/' });
					
									btn_compare_check_enabled();
									
									alert("The cookie is: "+$.cookie("compare_item_cookie_single"));
									
									return false;
								}
						}
					);
					
					
	//IF CART IS EMPTY REMOVE THE COOKIE						
					if(compare_count == 0){
						$.cookie("compare_item_cookie_single",null,{ path: '/' });
						$("#compare_cart").slideUp(100);
						$('table#compare-cart-table').removeAttr("class");
					}
	//				else {
	//					$.cookie("compare_count_cookie",compare_count,{ path: '/' });
	////					alert("The cookie is now DECREMENTED TO = "+$.cookie("compare_count_cookie"));
	//				}
				}
				if(compare_cart_table_class != compare_product_type){
					alert("The Compare cart has been updated. It now contains product(s) of a different type.");
					$(".compare-checkbox").attr('checked', false);
					$("table#compare-cart-table tr:first-child td").each(function(index){
						$(this).attr("id", "compare_item");
						$(this).html(
							"<div class='remove_item compare-product-remove'></div>" +
							"<div class='compare-product-title compare-product'></div>"
						);
						$(this).removeAttr("style");//doesn't work in IE 6,7,8
//						$(this).prop("style",null);
						$('table#compare-cart-table').removeAttr("class");
					});
					update_cart_on_refresh();
				}
			}
			
			function set_cookie(checkbox_id,product_type){
//				alert("SKU IS="+checkbox_id+"\nPRODUCT ="+product_type);
				var compare_item_cookie_single = new Object();
				product_sku_list = new Array();
				compare_count = 1;
				compare_product_type = product_type;
				
				product_sku_list.push(checkbox_id);
								
				compare_item_cookie_single.sku = product_sku_list.join(',');
				compare_item_cookie_single.count = compare_count;
				compare_item_cookie_single.product = product_type;
				
//				alert("[1]	sku= "+compare_item_cookie_single.sku+"\ncount= "+compare_item_cookie_single.count+"\nproduct= "+compare_item_cookie_single.product);
				
				$.cookie("compare_item_cookie_single",JSON.stringify(compare_item_cookie_single),{ path: '/' });				
			}
			function update_cookie(sku,product_type){
				
				compare_item_cookie_single = JSON.parse($.cookie("compare_item_cookie_single"));
				product_sku = compare_item_cookie_single.sku;
				count = compare_item_cookie_single.count;
				compare_product_type = compare_item_cookie_single.product;
				
				if(compare_product_type != product_type){
					var clear_cart_answer = confirm("The cart contains product of a different type. Do you wish to clear the cart and this item?");
					if(clear_cart_answer == true){
//						alert("Cart will now be cleared.");
						reset_compare_list();
						set_cookie(sku,product_type);
						$(".compare-checkbox#"+sku).attr('checked', true);
//						$.cookie("compare_product_type",product_type,{ path: '/' });
						return true;
					}
					else{
//						alert("Cart will not be cleared.");
						return false;
					}
				}
				
				
				compare_count = parseInt(count);
//			alert("The count was = "+compare_count);
				compare_count++;
//			alert("The count increased to = "+compare_count);
				
//			alert("PRODUCT SKU LIST= "+product_sku);
//			alert("PRODUCT TO BE PUSHED= "+sku);
				product_sku_list = product_sku.split(',');
//			alert("SKU LIST = "+product_sku_list);
				product_sku_list.push(sku);
//			alert("After Pushing= "+product_sku_list);	
				compare_item_cookie_single.sku = product_sku_list.join(',');
				compare_item_cookie_single.count = compare_count;

				
//				alert("[2]	sku= "+compare_item_cookie_single.sku+"\ncount= "+compare_item_cookie_single.count+"\nproduct= "+compare_item_cookie_single.product);
				
				$.cookie("compare_item_cookie_single",JSON.stringify(compare_item_cookie_single),{ path: '/' });
				
				return true;
			}
			
//WHEN THE ADD TO COMPARE OF A ITEM IS CHECKED THIS FUNCTION EXECUTES			
			$(".compare-checkbox").live("click", function(){
				var checkbox_id = $(this).attr("id");
				var checkbox_class = $(this).attr("class").split(" ");
				product_type = checkbox_class[1];
											
				if($(this).is(':checked')) {	
					if($.cookie("compare_item_cookie_single") == null){
//						alert("CHECKBOX IS="+checkbox_id+"\nPRODUCT TYPE="+product_type);
						set_cookie(checkbox_id,product_type);
					}
					else{
//						alert("CHECKBOX IS="+checkbox_id);
						if(!update_cookie(checkbox_id,product_type)){
							return false;
						}
						
					}
	
//					alert($.cookie("compare_item_cookie_single"));

					compare_item_cookie_single = JSON.parse($.cookie("compare_item_cookie_single"));
					count = compare_item_cookie_single.count;
					compare_count = parseInt(count);

//					alert("RETREIVING COMPARE COUNT FROM COOKIE; VALUE IS = "+compare_count);
//if 4 items are added make all the other checkboxes disabled				
					if (compare_count == 4)	{
						$(".compare-checkbox").attr("disabled", true);
					}
	//if more than 1 item has been added to compare cart make compare button enabled				
					btn_compare_check_enabled(compare_count);
					
//get the added items image and title using ajax
					get_item_image(checkbox_id,compare_count,product_type);

					$("#compare_cart").slideDown(500, function(){
						$(this).css("display", "static");
						$(this).css("position", "relative");
						$(this).css("top", "25%");
					});	

					
				}

				

				
				
////			alert("checkbox_id= "+checkbox_id+"\ncheckbox_class= "+checkbox_class+"\nproduct_type "+product_type);	
//				if($(this).is(':checked')) {				
//					if($.cookie("compare_product_type") != null){
//						compare_product_type = $.cookie("compare_product_type");
//					}
//					else {
//						$.cookie("compare_product_type",product_type,{ path: '/' });
//						compare_product_type = product_type;
//					}
////					alert("The compare product type is: "+product_type);
////					alert("The compare product type cookie is: "+$.cookie("compare_product_type"));
//					
//					if(compare_product_type != product_type){
//						var clear_cart_answer = confirm("The cart contains product of a different type. Do you wish to clear the cart and this item?");
//						if(clear_cart_answer == true){
////							alert("Cart will now be cleared.");
//							reset_compare_list();
//							$(".compare-checkbox#"+checkbox_id).attr('checked', true);
//							$.cookie("compare_product_type",product_type,{ path: '/' });
//						}
//						else{
////							alert("Cart will not be cleared.");
//							return false;
//						}
//					}
//					
//	//				alert(product_type);
//	//				$(this).attr("disabled", true);
//	//					alert("checkbox_id = "+checkbox_id);
//	//				var item = document.getElementById("compare_item");
//	//				item.id = checkbox_id;
//					
//	//Adding the current id to the cookie
//							compare_item_cookie = $.cookie("compare_item_cookie") ? $.cookie("compare_item_cookie").split(',') : new Array();
//							//THIS OPERATION IS NOT REQUIRED
//							//BECAUSE IF COOKIE IS ALREADY SET THEN THE CHECKBOX WILL BE CHECKED FOR THE ITEM
//							//SO CHECKING BECOMED UNNECCESARY
//							//KEEPING THIS FOR NOW BECAUSE ABOVE OPERATION HAS NOT BEEN IMPLEMENTED
//							var flag=1;//to check if the cookie for this item is already set
//	//						alert("Empty"+compare_item_cookie+" "+checkbox_id);
//							$.each(compare_item_cookie,function(index) {
//	//									alert(compare_item_cookie[index]);
//										if (compare_item_cookie[index] == checkbox_id) {
//											flag = 0;
//											return false;
//										}
//								}
//							);
//							if (flag == 1) {
//								compare_item_cookie.push(checkbox_id);
//	//							alert("New cookie item set"+compare_item_cookie+" "+checkbox_id+" the index value for 0"+compare_item_cookie[0]);
//							}
//							$.cookie("compare_item_cookie", compare_item_cookie.join(','),{ path: '/' });
////							alert("The compare_item_cookie is = "+$.cookie("compare_item_cookie"));
//					
//	//				if($.cookie("item-id"+compare_count) == null) {
//	//					$.cookie("item-id"+compare_count,checkbox_id,{ path: '/' });
//	//					alert("A cookie is now set"+$.cookie("item-id"+compare_count));
//	//				}
//	
//	//if 4 items are added make all the other checkboxes disabled						
//					if (compare_count == 4)	{
//						$(".compare-checkbox").attr("disabled", true);
//					}
//	//if more than 1 item has been added to compare cart make compare button enabled				
//					btn_compare_check_enabled();
//					
//					
//					if($.cookie("compare_count_cookie") != null){
//						compare_count = parseInt($.cookie("compare_count_cookie"));
//	//					alert("The count was = "+compare_count);
//						compare_count++;
//	//					alert("The count has been incremented to = "+compare_count);
//						$.cookie("compare_count_cookie",compare_count,{ path: '/' });
//	//					alert("The cookie is now = "+$.cookie("compare_count_cookie"));
//					}
//					else {
//						$.cookie("compare_count_cookie","1",{ path: '/' });
//	//					alert("The count cookie is now set to = "+$.cookie("compare_count_cookie"));
//					}
////					alert("The count cookie is = "+$.cookie("compare_count_cookie"));
//	//get the added items image and title using ajax
//					compare_count = parseInt($.cookie("compare_count_cookie"));
////					alert("compare_count="+compare_count);
//					get_item_image(checkbox_id,compare_count);
//	//				
//					
//	//				$.ajax({
//	//						type: "GET",
//	//						url: Drupal.settings.basePath + '/compare_item_get_image',
//	//						dataType: 'json',
//	//						data: "id=" + encodeURI(checkbox_id),
//	//						success: function(result){
//	//					
//	////					alert(result);
//	//
//	//								var image_element = document.getElementById(item.id).getElementsByTagName("img");
//	//								var span_element = document.getElementById(item.id).getElementsByTagName("span");
//	//								image_element[0].setAttribute("src", result);
//	////							span_element[0].setAttribute("title", "Remove");
//	//								span_element[0].innerHTML = "<img src='/compare/sites/all/modules/compare_item/images/remove.gif' />";
//	//					}
//	//				
//	//				});
//	
//	        
//					$("#compare_cart").slideDown(500, function(){
//						$(this).css("display", "static");
//						$(this).css("position", "relative");
//						$(this).css("top", "25%");
//					});	
//				}
				else {
//					alert("this item will be removed......please please please !");
					remove_compare_cart_item(checkbox_id);
				}
			});

//WHEN THE AN ITEM IS REMOVED FROM THE COMPARE CART THIS FUNCTION EXECUTES			
			$(".compare-product-remove").live('click', function(){
//				$(this).hide("fast", function(){
					var id = $(this).parent().attr("id");
					remove_compare_cart_item(id);

					$(".compare-checkbox#"+id).attr('checked', false);
//					alert($(".compare-checkbox#"+id).attr("id"));
					
										
//					$('table#compare-cart-table td#'+id).remove();
//					$('table#compare-cart-table tr:first-child td:nth-child(3)').after(
//						"<td name='compare_item' id='compare_item'>" +
//						"	<div class='div_image compare-product compare-product-image'>" +
//						"		<img src='/compare/sites/all/modules/compare_item/images/add_item.jpg' class='image' height='50px' width='50px' />" +
//						"	</div>" +
//						"	<div class='remove_item compare-product-remove'></div>" +
//						"	<div class='compare-product-title compare-product'></div>" +
//						"</td>"
//					);
////					var empty_item = Drupal.settings.basePath+'sites/all/modules/compare_item/images/add_item.jpg';
////					$('table#compare-cart-table td#'+id+' div.compare-product-image').html('<img src="'+empty_item+'" class="image" height="50px" width="50px"/>');
////					$('table#compare-cart-table td#'+id+' div.compare-product-title').empty();
////					$('table#compare-cart-table td#'+id+' div.compare-product-remove').empty();
////					alert(".compare-checkbox#"+id);
//
////					alert($(".compare-checkbox#"+id).attr("id"));
////					$(".compare-checkbox#"+id).attr('checked', false);
//					
////					var remove_item_id = document.getElementById(id);
////					$("div#"+id).remove();
////
////				
////Removing the current id from cookie
//						remove_item_cookie = $.cookie("compare_item_cookie").split(',');
////						alert("To remove"+remove_item_cookie+" "+id);
//						$.each(remove_item_cookie,function(index) {
////									alert(compare_item_cookie[index]);
//									if (remove_item_cookie[index] == id) {
//										remove_item_cookie.splice(index,1);
//										return false;
//									}
//							}
//						);
//						$.cookie("compare_item_cookie", remove_item_cookie.join(','),{ path: '/' });
////						alert("The id cookie has been set to => "+$.cookie("compare_item_cookie"));
//
////DECREMENTING THE COUNT VALUE BY 1
//						compare_count = parseInt($.cookie("compare_count_cookie"));
////						alert("The count BEFORE DECREMENT was = "+compare_count);
//						compare_count--;
////						alert("The count has been DECREMENTED to = "+compare_count);
//
////IF CART IS EMPTY REMOVE THE COOKIE						
//						if(compare_count == 0){
//							$.cookie("compare_item_cookie",null);
//							$.cookie("compare_count_cookie",null);
//							$.cookie("compare_product_type",null);
//						}
//						else {
//							$.cookie("compare_count_cookie",compare_count,{ path: '/' });
////							alert("The cookie is now DECREMENTED TO = "+$.cookie("compare_count_cookie"));
//						}
//						
//						
////					$.cookie("item-id",null);
//
////					
////					new_compare_item = $("<div/>");
////					new_compare_item.attr("id", "compare_item");
////					new_compare_item.attr("name", "compare_item");
////					new_compare_item.addClass("div_image");
////					new_compare_item.append($("<img/>")
////							.addClass("image")
////							.attr("src", "/compare/sites/all/modules/compare_item/images/add_item.jpg")
////							.attr("height", 50)
////							.attr("width", 50));
////					alert(new_compare_item);
////					new_compare_item.append($("<span/>")
////							.addClass("remove_item")
////							.click(function(){
////								$(this).parent().remove();
////							}));
////              
////					$("#compare_block").append(new_compare_item);
////					
////					$("input#"+id).attr("disabled", false);
////					$("input#"+id).attr("checked", false);
////					
////					compare_count--;
////					compare_compare_count--;
////					
//					btn_compare_check_enabled();
////					$(":checkbox").each(function(){
////						if (($(this).attr("checked")) == false){
////							$(this).attr("disabled", false);
////						}
////					});
////				});
			});
			
			
			function reset_compare_list(){
				compare_count = 0;
				
//Removing the cookies
				$.cookie("compare_item_cookie_single",null,{ path: '/' });
				
				$(".compare-checkbox").attr('checked', false);
				
				$("table#compare-cart-table tr:first-child td").each(function(index){
					$(this).attr("id", "compare_item");
					$(this).html(
//						"<div class='div_image compare-product compare-product-image'>" +
//						"	<img src='/compare/sites/all/modules/compare_item/images/add_item.jpg' class='image' height='50px' width='50px' />" +
//						"</div>" +
						"<div class='remove_item compare-product-remove'></div>" +
						"<div class='compare-product-title compare-product'></div>"
					);
					$(this).removeAttr("style");//doesn't work in IE 6,7,8
//					$(this).prop("style",null);
					$('table#compare-cart-table').removeAttr("class");
//					$(this).children("img").attr("src", "/compare/sites/all/modules/compare_item/images/add_item.jpg");
//					$(this).children("span").children("img").remove();
				});
//				$(":disabled").attr("disabled", false);
//				$(":checked").attr("checked", false);
			}
	
			$(".compare_cart_close").click(function(){
				reset_compare_list();
				btn_compare_check_enabled();
				$("#compare_cart").slideUp(100);
			});
			
			$(".compare_cart_clear").click(function(){
				reset_compare_list();
				btn_compare_check_enabled();
			});
			
			function btn_compare_check_enabled(){
				if (compare_count >= 2) {
					document.getElementById("btn_compare").disabled = false;
				}
				else {
					document.getElementById("btn_compare").disabled = true;
				}
//				return;
			}
			
			$("#btn_compare").click(function() {
				compare_item_cookie_single = JSON.parse($.cookie("compare_item_cookie_single"));
				product_sku = compare_item_cookie_single.sku;
				count = compare_item_cookie_single.count;
				compare_product_type = compare_item_cookie_single.product;
				
//				var product_type = $.cookie("compare_product_type");
//				alert("The product is = "+$.cookie("compare_product_type"));
				var link_compare_page = "http://localhost"+Drupal.settings.basePath+compare_product_type+"/comparepage/";
//				alert($.cookie("compare_item_cookie"));
				var compare_product_sku_list = product_sku;
//				alert(compare_product_sku_list);
				link_compare_page += compare_product_sku_list;
				alert(link_compare_page);
//				$("[name='compare_item']").each(function(index){
////					alert("sdsd");
////					alert($(this).attr("id"));
//					if($(this).attr("id") != "compare_item"){
////						alert($(this).attr("id"));
//						link_compare_page += "\\"+$(this).attr("id");
//					}
//				});
////				alert(link_compare_page);
				window.location=link_compare_page;
			});
			
	}
	
	Drupal.behaviors.compare = {
			attach: function(context)  {
				comparefunction(context);
			}
	};
})(jQuery);
