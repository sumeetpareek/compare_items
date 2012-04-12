(function($)  {
	function comparefunction(context)  {
			var checkbox_id;
			var count = 0;
			var compare_count = 0;
//			compare_item_cookie = $.cookie("compare_item_cookie") ? $.cookie("compare_item_cookie").split(',') : new Array();
			document.getElementById("btn_compare").disabled = true;
			
			var product_class_list = $(".content .view-display-id-page").attr("class");
			var product_class_list_array = product_class_list.split(" ");
			var checkbox_id;
			
//			alert(product_class_list_array[4]);
			$("#compare_cart").attr("class",product_class_list_array[4]);
			$(".compare").each(function(){
				checkbox_id = $(this).attr("id");
//				alert("Checkbox id"+checkbox_id);
				$("#"+checkbox_id).parents("div.views-field").attr("id",checkbox_id);
			});
			
			if($.cookie("compare_item_cookie") != null) {
				compare_item_cookie = $.cookie("compare_item_cookie").split(',');
				alert("Already set cookie is: "+compare_item_cookie);
				$.each(compare_item_cookie,function(index) {
							alert(compare_item_cookie[index]);
							get_item_image(compare_item_cookie[index]);
					}
				);
			}
			
			function get_item_image(id) {
				$.ajax({
					type: "GET",
					url: Drupal.settings.basePath + '/compare_item_get_image',
					dataType: 'json',
					data: "id=" + encodeURI(id),
					success: function(result){
				alert(result);
								var image_element = document.getElementById(id).getElementsByTagName("img");
//								alert("line 1"+image_element);
								var span_element = document.getElementById(id).getElementsByTagName("span");
//								alert("line 2");
								image_element[0].setAttribute("src",result);
//								alert("line 3");
								span_element[0].setAttribute("title", "Remove");
								span_element[0].innerHTML = "<img src='/compare/sites/all/modules/compare_item/images/remove.gif' />";
					}
				});
			}
			
			
			
			$(".compare").live("click", function(){
				var checkbox_id = $(this).attr("id");
				$(this).attr("disabled", true);
				
				var item = document.getElementById("compare_item");
				item.id = checkbox_id;
				count++;
				compare_count++;
				
//Adding the current id to the cookie
						compare_item_cookie = $.cookie("compare_item_cookie") ? $.cookie("compare_item_cookie").split(',') : new Array();
						var flag=1;
						alert("Empty"+compare_item_cookie+" "+checkbox_id);
						$.each(compare_item_cookie,function(index) {
		//							alert(compare_item_cookie[index]);
									if (compare_item_cookie[index] == checkbox_id) {
										flag = 0;
										return false;
									}
							}
						);
						if (flag == 1) {
							compare_item_cookie.push(checkbox_id);
							alert("New cookie item set"+compare_item_cookie+" "+checkbox_id+" the index value for 0"+compare_item_cookie[0]);
						}
						$.cookie("compare_item_cookie", compare_item_cookie.join(','));
						alert($.cookie("compare_item_cookie"));
				
//				if($.cookie("item-id"+compare_count) == null) {
//					$.cookie("item-id"+compare_count,checkbox_id);
//					alert("A cookie is now set"+$.cookie("item-id"+compare_count));
//				}
				
				if (count == 4)	{
					$(":checkbox").attr("disabled", true);
				}
				btn_compare_check_enabled();
				

				get_item_image(checkbox_id)
//				$.ajax({
//						type: "GET",
//						url: Drupal.settings.basePath + '/compare_item_get_image',
//						dataType: 'json',
//						data: "id=" + encodeURI(checkbox_id),
//						success: function(result){
//					
////					alert(result);
//
//								var image_element = document.getElementById(item.id).getElementsByTagName("img");
//								var span_element = document.getElementById(item.id).getElementsByTagName("span");
//								image_element[0].setAttribute("src", result);
////							span_element[0].setAttribute("title", "Remove");
//								span_element[0].innerHTML = "<img src='/compare/sites/all/modules/compare_item/images/remove.gif' />";
//					}
//				
//				});

        
				$("#compare_cart").slideDown(500, function(){
					$(this).css("display", "static");
					$(this).css("position", "relative");
					$(this).css("top", "25%");
				});				
			});
			
			$(".remove_item").live('click', function(){
				$(this).hide("fast", function(){
					var id = $(this).parent().attr("id");
					alert(id);
					var remove_item_id = document.getElementById(id);
					$("div#"+id).remove();

				
//Removing the current id from cookie
						remove_item_cookie = $.cookie("compare_item_cookie").split(',');
						alert("To remove"+remove_item_cookie+" "+id);
						$.each(remove_item_cookie,function(index) {
									alert(compare_item_cookie[index]);
									if (remove_item_cookie[index] == id) {
										remove_item_cookie.splice(index,1);
										return false;
									}
							}
						);
						$.cookie("compare_item_cookie", remove_item_cookie.join(','));
						alert($.cookie("compare_item_cookie"));
	//					$.cookie("item-id",null);

					
					new_compare_item = $("<div/>");
					new_compare_item.attr("id", "compare_item");
					new_compare_item.attr("name", "compare_item");
					new_compare_item.addClass("div_image");
					new_compare_item.append($("<img/>")
							.addClass("image")
							.attr("src", "/compare/sites/all/modules/compare_item/images/add_item.jpg")
							.attr("height", 50)
							.attr("width", 50));
					alert(new_compare_item);
					new_compare_item.append($("<span/>")
							.addClass("remove_item")
							.click(function(){
								$(this).parent().remove();
							}));
              
					$("#compare_block").append(new_compare_item);
					
					$("input#"+id).attr("disabled", false);
					$("input#"+id).attr("checked", false);
					
					count--;
					compare_count--;
					
					btn_compare_check_enabled();
					$(":checkbox").each(function(){
						if (($(this).attr("checked")) == false){
							$(this).attr("disabled", false);
						}
					});
				});
			});
			
			
			function reset_compare_list(){
				count = 0;
				compare_count = 0;
				
//Removing the cookie
					$.cookie("compare_item_cookie",null);
//				$.cookie("item-id",null);
				
				$("[name='compare_item']").each(function(index){
					$(this).attr("id", "compare_item");
					$(this).children("img").attr("src", "/compare/sites/all/modules/compare_item/images/add_item.jpg");
					$(this).children("span").children("img").remove();
				});
				$(":disabled").attr("disabled", false);
				$(":checked").attr("checked", false);
			}
	
			$("#aclose").click(function(){
				reset_compare_list();
				btn_compare_check_enabled();
				$("#compare_cart").slideUp(100);
			});
			
			$("#aclearlist").click(function(){
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
				return;
			}
			
			$("#btn_compare").click(function() {
				var link_compare_page="http://localhost/compare/viewtest2";
				$("[name='compare_item']").each(function(index){
//					alert("sdsd");
//					alert($(this).attr("id"));
					if($(this).attr("id") != "compare_item"){
//						alert($(this).attr("id"));
						link_compare_page += "\\"+$(this).attr("id");
					}
				});
//				alert(link_compare_page);
				window.location=link_compare_page;
			});
			
	}
	
	Drupal.behaviors.compare = {
			attach: function(context)  {
				comparefunction(context);
			}
	};
})(jQuery);
